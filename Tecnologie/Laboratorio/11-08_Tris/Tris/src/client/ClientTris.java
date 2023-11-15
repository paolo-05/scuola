package client;

import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

/**
 * The `ClientTris` class represents a Tic Tac Toe client application. It allows a player to connect to a server
 * and play the game with another player.
 */
public class ClientTris {

    private final JFrame frame = new JFrame("Tic Tac Toe");
    private JLabel messageLabel = new JLabel("");
    private ImageIcon icon;
    private ImageIcon opponentIcon;

    private Square[] board = new Square[9];
    private Square currentSquare;

    static final private int PORT = 8902;
    private Socket socket;
    private BufferedReader in;
    private PrintWriter out;

    /**
     * Creates a new `ClientTris` instance that connects to a Tic Tac Toe server.
     *
     * @param serverAddress The address of the server to connect to.
     * @throws Exception if there is an error in setting up the connection.
     */
    public ClientTris(String serverAddress) throws Exception {

        socket = new Socket(serverAddress, PORT);
        in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        out = new PrintWriter(socket.getOutputStream(), true);

        messageLabel.setBackground(Color.lightGray);
        frame.getContentPane().add(messageLabel, "South");

        JPanel boardPanel = new JPanel();
        boardPanel.setBackground(Color.black);
        boardPanel.setLayout(new GridLayout(3, 3, 2, 2));
        for (int i = 0; i < board.length; i++) {
            final int j = i;
            board[i] = new Square();
            board[i].addMouseListener(new MouseAdapter() {
                public void mousePressed(MouseEvent e) {
                    currentSquare = board[j];
                    out.println("MOVE " + j);
                }
            });
            boardPanel.add(board[i]);
        }
        frame.getContentPane().add(boardPanel, "Center");
    }

    /**
     * Starts the game and handles game interactions with the server and the opponent player.
     *
     * @throws Exception if there is an error during the game.
     */
    public void play() throws Exception {
        String response;
        try {
            response = in.readLine();
            if (response.startsWith("WELCOME")) {
                char mark = response.charAt(8);
                icon = new ImageIcon((mark == 'X') ? "/home/paolo/scuola/Tecnologie/Laboratorio/11-08_Tris/Tris/src/client/x.png" : "/home/paolo/scuola/Tecnologie/Laboratorio/11-08_Tris/Tris/src/client/o.png");
                opponentIcon = new ImageIcon((mark == 'X') ? "/home/paolo/scuola/Tecnologie/Laboratorio/11-08_Tris/Tris/src/client/o.png" : "/home/paolo//scuola/Tecnologie/Laboratorio/11-08_Tris/Tris/src/client/x.png");
                frame.setTitle("Tic Tac Toe - Player " + mark);
            }
            while (true) {
                response = in.readLine();
                if (response.startsWith("VALID_MOVE")) {
                    messageLabel.setText("Valid move, please wait");
                    currentSquare.setIcon(icon);
                    currentSquare.repaint();
                } else if (response.startsWith("OPPONENT_MOVED")) {
                    int loc = Integer.parseInt(response.substring(15));
                    board[loc].setIcon(opponentIcon);
                    board[loc].repaint();
                    messageLabel.setText("Opponent moved, your turn");
                } else if (response.startsWith("VICTORY")) {
                    messageLabel.setText("You win");
                    break;
                } else if (response.startsWith("DEFEAT")) {
                    messageLabel.setText("You lose");
                    break;
                } else if (response.startsWith("TIE")) {
                    messageLabel.setText("You tied");
                    break;
                } else if (response.startsWith("MESSAGE")) {
                    messageLabel.setText(response.substring(8));
                }
            }
            out.println("QUIT");
        } finally {
            socket.close();
        }
    }

    /**
     * Asks the player if they want to play the game again.
     *
     * @return `true` if the player wants to play again, `false` otherwise.
     */
    private boolean wantsToPlayAgain() {
        int response = JOptionPane.showConfirmDialog(frame,
                "Want to play again?",
                "Tic Tac Toe is Fun Fun Fun",
                JOptionPane.YES_NO_OPTION);
        frame.dispose();
        return response == JOptionPane.YES_OPTION;
    }

    /**
     * The `Square` class represents a square on the Tic Tac Toe board.
     */
    static class Square extends JPanel {
        JLabel label = new JLabel((Icon) null);

        /**
         * Creates a new `Square` instance.
         */
        public Square() {
            setBackground(Color.white);
            add(label);
        }

        /**
         * Sets the icon for the square.
         *
         * @param icon The icon to set.
         */
        public void setIcon(Icon icon) {
            label.setIcon(icon);
        }
    }

    /**
     * Starts up the client opening a new window.
     * @param args Command-line arguments, if specified the clients try to connect to the address provided in those args.
     * @throws Exception if there is an error in setting up the server or accepting client connections.
     */
    public static void main(String[] args) throws Exception {
        while (true) {
            String serverAddress = (args.length == 0) ? "localhost" : args[1];
            ClientTris client = new ClientTris(serverAddress);
            client.frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            client.frame.setSize(240, 160);
            client.frame.setVisible(true);
            client.frame.setResizable(false);
            client.play();
            if (!client.wantsToPlayAgain()) {
                break;
            }
        }
    }
}

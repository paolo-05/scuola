package server;
import java.net.ServerSocket;

/**
 * The `ServerTris` class represents a Tic Tac Toe server that pairs up clients that connect.
 * It listens for incoming client connections and manages the game sessions.
 *
 * @author paolo
 */
public class ServerTris {

    /**
     * This method runs the Tic Tac Toe server application. It creates and manages game sessions
     * by pairing up clients that connect to the server.
     *
     * @param args Command-line arguments (not used in this application).
     * @throws Exception if there is an error in setting up the server or accepting client connections.
     */
    public static void main(String[] args) throws Exception {
        try (ServerSocket listener = new ServerSocket(8902)) {
            System.out.println("Tic Tac Toe Server is Running");
            while (true) {
                Game game = new Game();
                Game.Player playerX = game.new Player(listener.accept(), 'X');
                Game.Player playerO = game.new Player(listener.accept(), 'O');
                playerX.setOpponent(playerO);
                playerO.setOpponent(playerX);
                game.currentPlayer = playerX;
                playerX.start();
                playerO.start();
            }
        }
    }
}

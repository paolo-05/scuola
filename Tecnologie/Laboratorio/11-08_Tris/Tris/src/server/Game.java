package server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

/**
 * The `Game` class represents a Tic Tac Toe game instance. It manages the game state and rules, including the board,
 * player moves, and determining the game outcome.
 *
 * @author paolo
 */
public class Game {

    private Player[] board = {
            null, null, null,
            null, null, null,
            null, null, null};

    Player currentPlayer;

    /**
     * Checks if there is a winner in the game.
     *
     * @return `true` if there is a winner, `false` otherwise.
     */
    public boolean hasWinner() {
        return
                (board[0] != null && board[0] == board[1] && board[0] == board[2])
                        ||(board[3] != null && board[3] == board[4] && board[3] == board[5])
                        ||(board[6] != null && board[6] == board[7] && board[6] == board[8])
                        ||(board[0] != null && board[0] == board[3] && board[0] == board[6])
                        ||(board[1] != null && board[1] == board[4] && board[1] == board[7])
                        ||(board[2] != null && board[2] == board[5] && board[2] == board[8])
                        ||(board[0] != null && board[0] == board[4] && board[0] == board[8])
                        ||(board[2] != null && board[2] == board[4] && board[2] == board[6]);
    }

    /**
     * Checks if the game board is completely filled up.
     *
     * @return `true` if the board is filled up, `false` otherwise.
     */
    public boolean boardFilledUp() {
        for (int i = 0; i < board.length; i++) {
            if (board[i] == null) {
                return false;
            }
        }
        return true;
    }

    /**
     * Checks if a move is legal and updates the game board accordingly.
     *
     * @param location The location on the board where the player wants to make a move.
     * @param player   The player making the move.
     * @return `true` if the move is legal, `false` otherwise.
     */
    public synchronized boolean legalMove(int location, Player player) {
        if (player == currentPlayer && board[location] == null) {
            board[location] = currentPlayer;
            currentPlayer = currentPlayer.opponent;
            currentPlayer.otherPlayerMoved(location);
            return true;
        }
        return false;
    }

    /**
     * The `Player` class represents a player in the Tic Tac Toe game.
     */
    class Player extends Thread {
        char mark;
        Player opponent;
        Socket socket;
        BufferedReader input;
        PrintWriter output;

        /**
         * Constructor for the `Player` class.
         *
         * @param socket The player's socket connection.
         * @param mark   The player's mark (either 'X' or 'O').
         */
        public Player(Socket socket, char mark) {
            this.socket = socket;
            this.mark = mark;
            try {
                input = new BufferedReader(
                        new InputStreamReader(socket.getInputStream()));
                output = new PrintWriter(socket.getOutputStream(), true);
                output.println("WELCOME " + mark);
                output.println("MESSAGE Waiting for opponent to connect");
            } catch (IOException e) {
                System.out.println("Player died: " + e);
            }
        }

        /**
         * Sets the opponent for this player.
         *
         * @param opponent The opponent player.
         */
        public void setOpponent(Player opponent) {
            this.opponent = opponent;
        }

        /**
         * Informs the player about the opponent's move.
         *
         * @param location The location where the opponent made a move.
         */
        public void otherPlayerMoved(int location) {
            output.println("OPPONENT_MOVED " + location);
            output.println(
                    hasWinner() ? "DEFEAT" : boardFilledUp() ? "TIE" : "");
        }

        /**
         * The player's main execution loop.
         */
        public void run() {
            try {
                output.println("MESSAGE All players connected");
                if (mark == 'X') {
                    output.println("MESSAGE Your move");
                }
                while (true) {
                    String command = input.readLine();
                    if (command.startsWith("MOVE")) {
                        int location = Integer.parseInt(command.substring(5));
                        if (legalMove(location, this)) {
                            output.println("VALID_MOVE");
                            output.println(hasWinner() ? "VICTORY"
                                    : boardFilledUp() ? "TIE"
                                    : "");
                        } else {
                            output.println("MESSAGE ?");
                        }
                    } else if (command.startsWith("QUIT")) {
                        return;
                    }
                }
            } catch (IOException e) {
                System.out.println("Player died: " + e);
            } finally {
                try { socket.close(); } catch (IOException e) {}
            }
        }
    }
}

package server;

import game.Game;
import java.io.*;
import java.net.*;
import java.util.concurrent.ThreadLocalRandom;

class ClientHandler implements Runnable {
    private Socket clientSocket;
    final private Game game;

    public ClientHandler(Socket socket, Game game) {
        this.clientSocket = socket;
        this.game = game;
    }

    @Override
    public void run() {
        try (PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
             BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()))) {

            synchronized (game) {
                game.registerClient(out);
            }

            while (true) {
                String input = in.readLine();
                if (input != null && input.equals("VINTO")) {
                    synchronized (game.gameLock) {
                        game.handleWin(out);
                        game.gameLock.notifyAll(); // Notify all waiting clients
                    }
                    break;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
package server;

import game.Game;
import java.io.*;
import java.net.*;

public class TombolaServer {
    public static void main(String[] args) {
        final int numClients = 5;
        Game game = new Game();

        try (ServerSocket serverSocket = new ServerSocket(12345)) {
            System.out.println("Server avviato. In attesa di " + numClients + " client...");

            for (int i = 0; i < numClients; i++) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Client " + (i + 1) + " connesso.");
                new Thread(new ClientHandler(clientSocket, game)).start();
            }

            game.startGame();

        } catch (IOException e) {
            System.out.println("Errore creazione socket");
        }
    }
}
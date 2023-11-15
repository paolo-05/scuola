package game;

import java.io.*;
import java.util.*;
import java.util.concurrent.ThreadLocalRandom;

public class Game {
    public final Object gameLock = new Object();
    private List<PrintWriter> clients = new ArrayList<>();
    static private int[] disponibili = new int[90];
    static private int extractedCount = 0;
    static private boolean won = false;

    public void registerClient(PrintWriter client) {
        clients.add(client);
    }

    public void startGame() {
        generateNumbers();
        while (extractedCount < 90 && !won) {
            int t = ThreadLocalRandom.current().nextInt(1, 91 - extractedCount);
            int num = disponibili[t];
            disponibili[t] = disponibili[90 - extractedCount - 1];

            synchronized (this) {
                for (PrintWriter client : clients) {
                    client.println(num);
                }
            }

            extractedCount++;

            try {
                Thread.sleep(500); // Wait between number extraction
            } catch (InterruptedException e) {
                System.out.println("Interrupted.");
            }
        }

        synchronized (this.gameLock) {
            for (PrintWriter client : clients) {
                client.println("Nessun client ha vinto.");
            }
        }
    }

    public void handleWin(PrintWriter winner) {
        synchronized (this) {
            for (PrintWriter client : clients) {
                if (client == winner) {
                    won = true;
                } else {
                    client.println("Il vincitore è il thread " + Thread.currentThread().threadId());
                }
            }
        }
    }
    static private void generateNumbers(){
        for (int i = 0; i < 90; i++) {
            disponibili[i] = i + 1;
        }
    }
}

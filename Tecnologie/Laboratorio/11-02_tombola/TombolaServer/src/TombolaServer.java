
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;

public class TombolaServer {

    private static final int PORT = 12345;
    private static final int NUM_CLIENTS = 5;
    private static final int NUM_NUMERI_TOMBOLA = 90;

    public static void main(String[] args) {
        ServerSocket serverSocket = null;
        List<TombolaClientHandler> clients = new ArrayList<>();
        List<Integer> numeriEstratti = new ArrayList<>();
        Random random = new Random();
        boolean estrazioneSospesa = false;
        int vincitore = -1;

        try {
            serverSocket = new ServerSocket(PORT);
            System.out.println("Server avviato. In attesa di " + NUM_CLIENTS + " client...");

            for (int i = 0; i < NUM_CLIENTS; i++) {
                Socket clientSocket = serverSocket.accept();
                TombolaClientHandler clientHandler = new TombolaClientHandler(clientSocket, i);
                clients.add(clientHandler);
                new Thread(clientHandler).start();
            }

            System.out.println("Tutti i client sono connessi. Inizio l'estrazione...");

            Timer timer = new Timer();
            timer.scheduleAtFixedRate(new TimerTask() {
                @Override
                public void run() {
                    if (!estrazioneSospesa) {
                        int numeroEstratto;
                        do {
                            numeroEstratto = random.nextInt(NUM_NUMERI_TOMBOLA) + 1;
                        } while (numeriEstratti.contains(numeroEstratto));

                        numeriEstratti.add(numeroEstratto);
                        System.out.println("Numero estratto: " + numeroEstratto);

                        for (TombolaClientHandler client : clients) {
                            client.inviaNumeroEstratto(numeroEstratto);
                            if (client.haCartellaCompleta()) {
                                estrazioneSospesa = true;
                                vincitore = client.getId();
                            }
                        }
                    } else {
                        System.out.println("Estrazione sospesa. Il vincitore è il Client " + vincitore);
                        timer.cancel();
                    }
                }
            }, 0, 5000);

        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (serverSocket != null) {
                    serverSocket.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}

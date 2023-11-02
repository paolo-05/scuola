package client;

import java.io.*;
import java.net.*;
import java.util.concurrent.ThreadLocalRandom;

public class TombolaClient {
    public static void main(String[] args) {
        String received;
        int i, receivedNumber, found = 0;
        try (Socket socket = new Socket("localhost", 12345);
             BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
             PrintWriter out = new PrintWriter(socket.getOutputStream(), true)) {

            System.out.println("Connessione al server riuscita.");
            System.out.println("Creazione della cartella...");
            int[] cartella = new int[10];
            int[] disponibili = new int[90];

            for (i = 0; i < disponibili.length; i++) {
                disponibili[i] = i + 1;
            }

            for (i = 0; i < cartella.length; i++) {
                int t = ThreadLocalRandom.current().nextInt(disponibili.length - i);
                cartella[i] = disponibili[t];
                disponibili[t] = disponibili[disponibili.length - i - 1];

                System.out.println("Numero " + (i + 1) + ": " + cartella[i]);
            }

            System.out.println("In attesa dei numeri estratti...");

            while (true) {
                received =  in.readLine();
                try {
                    receivedNumber = Integer.parseInt(received);
                }
                catch (NumberFormatException e){
                    receivedNumber = -1;
                    System.out.println("Hai perso");
                }
                if (received == null) {
                    break;
                }
                for (i = 0; i < cartella.length - found; i++) {
                    if (cartella[i] == receivedNumber){
                        cartella[i] = cartella[cartella.length - found - 1];
                        found++;
                    }
                }
                if (found == 10) {
                    out.println("VINTO");
                    System.out.println("Hai vinto!");
                    break;
                } else {
                    if(receivedNumber == -1){
                        System.out.println(received);
                        break;
                    }
                    System.out.println("Numero estratto: " + received);
                }
            }

        } catch (IOException e) {
            System.out.println("Errore nella connessione");
        }
    }
}

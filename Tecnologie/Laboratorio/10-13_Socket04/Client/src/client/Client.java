package client;

import java.io.*;
import java.net.*;

public class Client {

    public static void main(String[] args) {
        String serverAddress = "127.0.0.1"; // Indirizzo IP del server
        int serverPort = 12345; // Porta del server

        try {
            // Creare una connessione al server
            Socket socket = new Socket(serverAddress, serverPort);

            // Creare stream di input e output per comunicare con il server
            OutputStream outToServer = socket.getOutputStream();
            DataOutputStream out = new DataOutputStream(outToServer);
            InputStream inFromServer = socket.getInputStream();
            DataInputStream in = new DataInputStream(inFromServer);

            // La stringa da inviare al server
            String message = "Ciao, server!";

            // Invia la stringa al server
            out.writeUTF(message);

            // Ricevi la lunghezza del messaggio restituito dal server
            int messageLength = in.readInt();

            System.out.println("Messaggio inviato: " + message);
            System.out.println("Lunghezza del messaggio ricevuto dal server: " + messageLength);

            // Chiudi la connessione
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

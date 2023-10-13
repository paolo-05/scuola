package server;

import java.io.*;
import java.net.*;

public class Server {

    public static void main(String[] args) {
        int serverPort = 12345; // Porta su cui il server ascolta le connessioni

        try {
            // Crea un server socket che ascolta sulla porta specificata
            ServerSocket serverSocket = new ServerSocket(serverPort);

            System.out.println("Server in attesa di connessioni...");

            while (true) {
                // Accetta la connessione quando un client si connette
                Socket clientSocket = serverSocket.accept();

                // Crea stream di input e output per comunicare con il client
                InputStream inFromClient = clientSocket.getInputStream();
                DataInputStream in = new DataInputStream(inFromClient);
                OutputStream outToClient = clientSocket.getOutputStream();
                DataOutputStream out = new DataOutputStream(outToClient);

                // Leggi la stringa inviata dal client
                String clientMessage = in.readUTF();

                // Calcola la lunghezza della stringa
                int messageLength = clientMessage.length();

                // Invia la lunghezza al client
                out.writeInt(messageLength);

                System.out.println("Messaggio ricevuto dal client: " + clientMessage);
                System.out.println("Lunghezza del messaggio inviata al client: " + messageLength);

                // Chiudi la connessione con il client
                clientSocket.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

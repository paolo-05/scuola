/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package server;

import java.io.*;
import java.net.*;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Paolo
 */
public class Server {

    private int port;
    private ServerSocket server;

    public Server(int port) {
        this.port = port;
        if (!startServer()) {
            System.out.println("Non è stato possibile avviare il server");
        }
    }

    public void runServer() {
        while (true) {
            System.out.println("\nServer in attesa di richieste...");
            try {
                Socket s1 = server.accept();
                System.out.println("Un client si è connesso");
                OutputStream s1out = s1.getOutputStream();
                BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(s1out));

                // il server invia un messaggio al client
                bw.write("Benvenuto sul server");
                // chiusura dell'output stream
                bw.close();
                //chiusura socket
                s1.close();
                System.out.println("\nChiusura connessione avvenuta con successo!");
            } catch (IOException e) {
                System.out.println("\nErrore di comunicazione");
            }
        }
    }

    // metodo per avviare il server
    private boolean startServer() {
        try {
            server = new ServerSocket(port);
        } catch (IOException ex) {
            // Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("\nImpossibile creare socket");

            return false;
        }

        return true;
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Server mioServer = new Server(7999);
        mioServer.runServer();
    }

}

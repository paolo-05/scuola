/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package clientmaiu;

import java.io.*;
import java.net.*;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Paolo
 */
public class ClientMaiu {

    String nomeServer = "localhost";
    int port = 6789;
    Socket mioSocket;
    BufferedReader tastiera;
    DataOutputStream outVersoServer;
    BufferedReader inDaServer;

    String stringaUtente;
    String stringaRicevuta;

    public void comunica() {
        System.out.println("\n4 Inserisci una stringa, il server la "
                + "porterà in maiuscolo");
        try {
            stringaUtente = tastiera.readLine();
            System.out.println("\n5...invio della stringa al server e attendo...");
            outVersoServer.writeBytes(stringaUtente + "\n");

            // si legge la risposta del server
            stringaRicevuta = inDaServer.readLine();

            System.out.println("\n8...risposta server: " + stringaRicevuta);

            // chiusura connessione
            System.out.println("\n10 Client, chiusura connessione");
            mioSocket.close();
        } catch (IOException ex) {
            Logger.getLogger(ClientMaiu.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public void connetti() {
        System.out.println("\n2...Client partito in esecuzione");
        // input da tastiera
        tastiera = new BufferedReader(new InputStreamReader(System.in));

        try {
            // creazione socket
            mioSocket = new Socket(nomeServer, port);
            outVersoServer = new DataOutputStream(mioSocket.getOutputStream());
            inDaServer = new BufferedReader(new InputStreamReader(mioSocket.getInputStream()));
        } catch (IOException ex) {
            Logger.getLogger(ClientMaiu.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public static void main(String[] args) {
        ClientMaiu mioClient = new ClientMaiu();
        mioClient.connetti();
        mioClient.comunica();
    }

}

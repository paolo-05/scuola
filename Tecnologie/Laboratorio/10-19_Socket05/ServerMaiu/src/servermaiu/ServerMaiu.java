/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package servermaiu;

import java.io.*;
import java.net.*;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Paolo
 */
public class ServerMaiu {

    ServerSocket server = null;
    Socket client = null;
    String stringaRicevuta = "";
    String stringaModificata = "";

    BufferedReader inDaClient;
    DataOutputStream outVersoClient;

    public void attendi() {
        System.out.println("\n1 Server partito, in esecuzione...");
        try {
            // creaiamo un server sulla porta 6789
            server = new ServerSocket(6789);
            // atesa del client
            client = server.accept();
            // chiusura della socket
            server.close();
            // associazione degli oggetti per l'input/output al server
            inDaClient = new BufferedReader(new InputStreamReader(
                    client.getInputStream()));
            outVersoClient = new DataOutputStream(client.getOutputStream());
        } catch (IOException ex) {
            // Logger.getLogger(ServerMaiu.class.getName()).log(Level.SEVERE, null, ex
            System.out.println("\nImpossibile creare il server.");
            System.exit(1);
        }
    }

    public void comunica() {
        System.out.println("\n3 Benvenuto client, scrivi una frase e la trasformo "
                + "in maiuscolo. Attendo...");
        try {
            stringaRicevuta = inDaClient.readLine();
            System.out.println("\n6 Ricevuta la stringa dal client: " + stringaRicevuta);

            // si porta in maiuscolo la stringa ricevuta
            stringaModificata = stringaRicevuta.toUpperCase();
            System.out.println("\n7 invio della stringa modificata al client");

            outVersoClient.writeBytes(stringaModificata);

            System.out.println("\n9 Fine elaborazione...");
            client.close();
        } catch (IOException ex) {
            Logger.getLogger(ServerMaiu.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public static void main(String[] args) {
        ServerMaiu mioServer = new ServerMaiu();
        mioServer.attendi();
        mioServer.comunica();
    }

}

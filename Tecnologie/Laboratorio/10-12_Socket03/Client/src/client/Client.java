/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package client;

import java.io.*;
import java.net.*;

/**
 *
 * @author Paolo
 */
public class Client {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here

        try {
            // si apre una connessione verso il server/
            System.out.println("Apertura connessione");
            Socket sc = new Socket("127.0.0.1", 7999);
            InputStream scin = sc.getInputStream();
            BufferedReader br = new BufferedReader(new InputStreamReader(scin));
            System.out.println("\nMessaggio del server: " + br.readLine());
            br.close();
            sc.close();
        } catch (UnknownHostException e) {
            System.out.println("\nErroore nella ricerca dell'host");
        } catch (IOException e) {
            System.out.println("\nErrore nella comunicazione");
        }
    }

}

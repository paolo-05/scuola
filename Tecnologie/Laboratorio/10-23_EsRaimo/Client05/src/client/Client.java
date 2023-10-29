package client;

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Client {

    private Socket client;

    private DataInputStream in;
    private DataOutputStream out;

    private int num;

    public void comunica() {
        Scanner scanner = new Scanner(System.in);

        try {
            //Si apre la comunicazione verso il server utilizzando l'IP 127.0.0.1
            System.out.println("Apertura connessione");
            client = new Socket("127.0.0.1", 8000);

            System.out.println("Inserisci il numero da inviare al server:");
            num = scanner.nextInt();

            in = new DataInputStream(client.getInputStream());
            out = new DataOutputStream(client.getOutputStream());

            out.writeInt(num);

            System.out.println("Contatore: " + in.readInt());

            in.close();
            out.close();
            scanner.close();
            client.close();

        } catch (UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

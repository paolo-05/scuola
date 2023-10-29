package server;

import java.io.*;
import java.net.*;

public class ServerThread extends Thread {

    private Socket socket;
    private int num;
    private DataInputStream in;
    private DataOutputStream out;
    private Contatore contatore;

    public ServerThread(Socket socket, Contatore contatore) {
        this.socket = socket;
        this.contatore = contatore;
    }

    public void run() {
        comunica();
    }

    private void comunica() {
        System.out.println("Un client si è connesso");

        try {
            in = new DataInputStream(socket.getInputStream());
            out = new DataOutputStream(socket.getOutputStream());

            num = in.readInt();

            contatore.aumenta(num);

            out.writeInt(contatore.getValue());

            in.close();
            out.close();
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

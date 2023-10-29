package server;

import java.io.*;
import java.net.*;

public class Server {

    private ServerSocket server;
    final int port = 8000;
    private Contatore contatore = new Contatore();

    public void comunica() {

        try {
            server = new ServerSocket(port);

            while (true) {
                System.out.println("Server in attesa di richiesta");

                ServerThread thread = new ServerThread(server.accept(), contatore);
                thread.start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

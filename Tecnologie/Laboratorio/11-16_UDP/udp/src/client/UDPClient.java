package client;

import java.net.*;

public class UDPClient {
    public static void main(String[] args) {
        DatagramSocket socket = null;

        try {
            // Creazione del socket UDP
            socket = new DatagramSocket();

            // Indirizzo IP e numero di porta del server
            InetAddress serverAddress = InetAddress.getByName("localhost");
            int serverPort = 9876;

            // Dati da inviare al server
            String message = "Hello, Server!";
            byte[] sendData = message.getBytes();

            // Preparazione del pacchetto per l'invio
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, serverAddress, serverPort);

            // Invio dei dati al server
            socket.send(sendPacket);

            // Preparazione del pacchetto per ricevere la risposta dal server
            byte[] receiveData = new byte[1024];
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);

            // Ricezione della risposta dal server
            socket.receive(receivePacket);

            // Conversione della risposta in una stringa
            String response = new String(receivePacket.getData(), 0, receivePacket.getLength());
            System.out.println("Server Response: " + response);
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (socket != null && !socket.isClosed()) {
                socket.close();
            }
        }
    }
}

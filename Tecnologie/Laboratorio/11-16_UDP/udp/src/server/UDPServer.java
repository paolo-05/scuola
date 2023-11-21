package server;

import java.net.*;

public class UDPServer {
    public static void main(String[] args) {
        DatagramSocket socket = null;

        try {
            // Creazione del socket UDP
            socket = new DatagramSocket(9876);

            byte[] receiveData = new byte[1024];

            while (true) {
                // Preparazione del pacchetto per ricevere i dati
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);

                // Ricezione dei dati dal client
                socket.receive(receivePacket);

                // Conversione dei dati in una stringa
                String message = new String(receivePacket.getData(), 0, receivePacket.getLength());

                // Elaborazione dei dati (in questo caso, conversione in maiuscolo)
                String response = message.toUpperCase();

                // Ottenere l'indirizzo IP e il numero di porta del client
                InetAddress clientAddress = receivePacket.getAddress();
                int clientPort = receivePacket.getPort();

                // Preparazione dei dati da inviare al client
                byte[] sendData = response.getBytes();
                DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, clientAddress, clientPort);

                // Invio dei dati al client
                socket.send(sendPacket);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (socket != null && !socket.isClosed()) {
                socket.close();
            }
        }
    }
}

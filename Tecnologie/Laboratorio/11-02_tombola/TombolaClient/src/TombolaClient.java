
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class TombolaClient {

    private static final String SERVER_ADDRESS = "localhost";
    private static final int SERVER_PORT = 12345;
    static int[] cartella = new int[10];
    static boolean vinto = true;

    public static void main(String[] args) {
        try {
            try ( Socket socket = new Socket(SERVER_ADDRESS, SERVER_PORT)) {
                DataInputStream in = new DataInputStream(socket.getInputStream());
                DataOutputStream out = new DataOutputStream(socket.getOutputStream());
                generaCartella();
                for (int i = 0; i < 10; i++) {
                    if (cartella[i] != in.readInt()) {
                        vinto = false;
                    }
                }
                // Invia un messaggio al server quando hai tutti i tuoi numeri estratti
                if (vinto) {
                    out.writeChars("VINTO");
                }

                // Gestisci ulteriori comunicazioni con il server, ad esempio per ricevere
                // il messaggio del vincitore.
                System.out.println("Risposta Server:");
                System.out.println(in.readLine());

                // Chiudi la socket quando hai finito.
                in.close();
                out.close();
                socket.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

// Genera una cartella con 10 numeri casuali da 1 a 90
    static private void generaCartella() {
        Random random = new Random();
        int t;

        int[] disp = new int[90];
        System.out.println("ndisp");
        for (int i = 0; i < disp.length; i++) {
            disp[i] = i + 1;
            System.out.println(disp[i]);
        }
        for (int i = 0; i < cartella.length; i++) {
            t = random.nextInt(disp.length - i);
            cartella[i] = disp[t];

            disp[t] = disp[disp.length - 1];
        }
    }

    // Ricevi un numero estratto dal server
    private static int riceviNumeroEstratto(InputStream inputStream) {

        return 0; // Sostituisci con la logica effettiva
    }

    // Invia un messaggio al server per segnalare la vittoria
    private static void inviaMessaggioVittoria(OutputStream outputStream) {
        // Implementa l'invio di un messaggio al server per segnalare la vittoria
    }
}


import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.*;

public class TombolaClientHandler implements Runnable {

    private Socket clientSocket;
    private InputStream inputStream;
    private OutputStream outputStream;
    private int id;
    private List<Integer> cartella = new ArrayList<>();
    Random random = new Random();
    int numeroEstratto;

    public TombolaClientHandler(Socket socket, int i) {
        this.clientSocket = socket;
        this.id = i;
    }

    @Override
    public void run() {
        try {
            inputStream = clientSocket.getInputStream();
            outputStream = clientSocket.getOutputStream();

            for (int i = 0; i < 10 && cartella.contains(numeroEstratto); i++) {
                numeroEstratto = random.nextInt(90) + 1;
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (clientSocket != null) {
                    clientSocket.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public void inviaNumeroEstratto(int n) {

    }

    int getId() {
        return this.id;
    }
}

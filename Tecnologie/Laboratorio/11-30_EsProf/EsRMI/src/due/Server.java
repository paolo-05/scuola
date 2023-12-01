package due;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server {
    public static void main(String[] args) {
        try {
            // Crea un'istanza dell'oggetto remoto
            SumInterface addObj = new AddClass();

            // Registra l'oggetto remoto con il registry sulla porta 1099
            Registry rg = LocateRegistry.createRegistry(1199);
            rg.rebind("adder", addObj);

            System.out.println("Server ready");
        } catch (Exception e) {
            System.err.println("Server exception: " + e.toString());
            e.printStackTrace();
        }
    }
}

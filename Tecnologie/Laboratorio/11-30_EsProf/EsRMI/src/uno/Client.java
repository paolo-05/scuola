package uno;

import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client {
    public static void main(String[] args) {
        try {
            // Ottieni l'oggetto remoto dal registry
            Registry registry = LocateRegistry.getRegistry(1199);
            SumInterface addObj = (SumInterface) registry.lookup("adder");

            // Esegui la somma richiamando il metodo remoto
            int result = addObj.somma(5, 7);

            // Stampa il risultato
            System.out.println("Result: " + result);
        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
    }
}

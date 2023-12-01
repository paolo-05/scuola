// Client.java
package due;

import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client {
    public static void main(String[] args) {
        try {
            // Ottieni l'oggetto remoto dal registry
            Registry registry = LocateRegistry.getRegistry(1199);
            SumInterface addObj = (SumInterface) registry.lookup("adder");
            // Usa getters per ottenere i valori di x e y
            int xValue = addObj.getX();
            int yValue = addObj.getY();

            System.out.println("Initial values - X: " + xValue + ", Y: " + yValue);

            // Usa setters per modificare i valori di x e y
            addObj.setX(5);
            addObj.setY(7);

            // Esegui la somma richiamando il metodo remoto
            int result = addObj.sum();

            // Stampa il risultato
            System.out.println("Result: " + result);
        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
    }
}

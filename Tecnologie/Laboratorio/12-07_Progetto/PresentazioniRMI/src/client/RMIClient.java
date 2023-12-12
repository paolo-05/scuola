package client;

import server.PresentationService;
import shared.PresentationServiceInterface;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

public class RMIClient {
    public static void main(String[] args) throws RemoteException, NotBoundException {
        boolean go = true;
        Registry registry = LocateRegistry.getRegistry(1099);
        PresentationServiceInterface presentationService = (PresentationServiceInterface) registry.lookup("PresentationService");
        while (go) {
            Scanner keyboard = new Scanner(System.in);
            System.out.println("\nGestione Presentazioni\n" +
                    "Cosa vuoi fare?\n 1-Creare una Presentazione\n" +
                    " 2-Partecipare a una presentazione\n" +
                    " 3-Avere il numero di presentazioni attive\n" +
                    " 4-uscire");
            int choice = keyboard.nextInt();
            switch (choice) {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    System.out.println("Al momento ci sono attive " + presentationService.getActivePresentationsCount() + " presentazioni.");
                    break;
                default:
                    go = false;
                    break;
            }
        }
    }
}

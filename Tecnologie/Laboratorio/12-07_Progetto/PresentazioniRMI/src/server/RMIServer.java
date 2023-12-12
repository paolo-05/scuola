package server;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class RMIServer {
    public static void main(String[] args) {
        try {
            PresentationService presentationService = new PresentationService();
            Registry registry = LocateRegistry.createRegistry(1099);
            registry.rebind("PresentationService", presentationService);

            System.out.println("RMI Server started.");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

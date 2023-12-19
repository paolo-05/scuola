package server;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class RMIServer {
    public static void main(String[] args) {
        try {
            LocateRegistry.createRegistry(1099);
            System.out.println("RMI server started");
            while (true) {
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

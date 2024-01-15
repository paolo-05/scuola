package server;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Main {
    public static void main(String[] args) throws RemoteException, InterruptedException {
        Registry registry = LocateRegistry.createRegistry(5000);
        TabelloneReale tabellone = new TabelloneReale(3);
        registry.rebind("tabellone", tabellone);
        tabellone.estrazione();
    }
}

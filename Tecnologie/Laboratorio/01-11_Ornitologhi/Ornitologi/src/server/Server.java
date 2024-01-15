package server;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server {
    public static void main(String[] args) {

        try {
            AppClass app = new AppClass();
            Registry registry = LocateRegistry.createRegistry(1099);
            registry.rebind("app", app);
            System.out.println("OrnitologoRMI server started");
        }
        catch (Exception e){
            System.out.println(e);
        }
    }
}

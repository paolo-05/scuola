package server;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class ServerRMI {

    public static void main(String[] args) {

        try {
            Congresso congresso = new Congresso();
            Registry registry = LocateRegistry.createRegistry(1099);
            registry.rebind("congresso", congresso);
            System.out.println("CongressoRMI server started");
        }
        catch (Exception e){
            System.out.println(e);
        }
    }

}

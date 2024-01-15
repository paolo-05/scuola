package client;

import interfaces.TabelloneBingo;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws RemoteException, NotBoundException {
        Registry registry = LocateRegistry.getRegistry(5000);
        TabelloneBingo tabelloneRemoto = (TabelloneBingo) registry.lookup("tabellone");
        System.out.println(tabelloneRemoto.numeriRimanenti());
        System.out.println("inserire numero desiderato");
        Scanner inputScanner = new Scanner(System.in);
        int luckyNumber = inputScanner.nextInt();
        Risultato result = new Risultato();
        tabelloneRemoto.scegliNumero(luckyNumber, result);
    }
}

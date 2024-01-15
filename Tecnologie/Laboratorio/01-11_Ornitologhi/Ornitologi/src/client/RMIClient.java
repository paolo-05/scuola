package client;

import shared.AppInterface;
import shared.Coordinata;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

public class RMIClient {
    static private void handleAvistamento(Scanner keyboard, AppInterface app){
        keyboard.nextLine();

        System.out.println("Inserisci il nome dell'ucello:");
        String nome = keyboard.nextLine();

        System.out.println("Inserisci la longitudine in GRADI!");
        double lo = keyboard.nextDouble();

        System.out.println("Inserisci la latitudine in GRADI!");
        double la = keyboard.nextDouble();



        try {
            Coordinata c = new Coordinata(la, lo);
            app.segnala(nome, c);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static private void handleLasts(Scanner keyboard, AppInterface app){
        try {
            System.out.println(app.getUltimi());
        } catch (RemoteException e) {
            throw new RuntimeException(e);
        }
    }

    static private void handleZona(Scanner keyboard, AppInterface app){
    }

    public static void main(String[] args) {
        try {
            Registry registry = LocateRegistry.getRegistry(1099);
            AppInterface app = (AppInterface) registry.lookup("app");
            Scanner keyboard = new Scanner(System.in);
            while(true) {
                System.out.println(
                        "Gestione Ornitologi\n" +
                                "Cosa vuoi fare?\n" +
                                "1-segnalare un avvistamento\n" +
                                "2-stampare gli ultimi 5 avvistamenti\n" +
                                "3-aggiornamento sulla zona\n"+
                                "4-esci");
                switch (keyboard.nextInt()){
                    case 1:
                        handleAvistamento(keyboard, app);
                        break;
                    case 2:
                        handleLasts(keyboard, app);
                        break;
                    case 3:
                        handleZona(keyboard, app);
                        break;
                    default:
                        return;
                }
            }
        }catch (Exception e){
            e.printStackTrace();
        }
    }

}

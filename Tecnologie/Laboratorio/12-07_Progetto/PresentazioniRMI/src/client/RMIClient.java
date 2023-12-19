package client;

import shared.PresentationInterface;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Objects;
import java.util.Scanner;

public class RMIClient {
    private static void handlePresentator(Registry registry, Scanner keyboard) throws RemoteException, NotBoundException {
        boolean go = true;
        PresentationRoom room = new PresentationRoom();
        String[] rooms = registry.list();
        String roomNane = "Stanza " + ((rooms.length) + 1);

        registry.rebind(roomNane, room);
        System.out.println(roomNane + " creata");

        System.out.println("Per chiudere Digitare QUIT");
        while(go){
            if(Objects.equals(keyboard.nextLine(), "QUIT")){
                go = false;
            }
        }
        registry.unbind(roomNane);
        UnicastRemoteObject.unexportObject(room, true);
    }

    private static  void handleClient(Registry registry, Scanner keyboard) throws NotBoundException, RemoteException {
        System.out.println("Inserire nome della stanza a cui unirsi");
        PresentationInterface room = (PresentationInterface) registry.lookup(keyboard.nextLine());
        System.out.println("Entrato con successo nella stanza, per uscire QUIT.");
        while (true){
            String message = keyboard.nextLine();
            if(message.equals("QUIT")){
                break;
            }else{
                room.feedback(message);
            }
        }
    }

    public static void main(String[] args) throws RemoteException, NotBoundException {
        Registry registry = LocateRegistry.getRegistry(1099);
        Scanner keyboard = new Scanner(System.in);
        while (true) {
            System.out.println(
                    "\nGestione Presentazioni\n" +
                    "Cosa vuoi fare?\n" +
                    " 1-Creare una Presentazione\n" +
                    " 2-Partecipare a una presentazione\n" +
                    " 3-Avere il numero di presentazioni attive\n" +
                    " 4-uscire");
            int choice = keyboard.nextInt();
            keyboard.nextLine();
            switch (choice) {
                case 1:
                    handlePresentator(registry, keyboard);
                    break;
                case 2:
                    handleClient(registry, keyboard);
                    break;
                case 3:
                    String[] rooms  = registry.list();
                    System.out.println("Stanze in contemporanea:");
                    for (String room : rooms) {
                        System.out.println(room);
                    }
                    break;
                default:
                    return;
            }
        }
    }
}

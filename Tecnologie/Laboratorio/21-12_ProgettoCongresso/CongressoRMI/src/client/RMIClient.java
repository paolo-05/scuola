package client;

import shared.CongressoInterface;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

public class RMIClient {
    static void handleNewSpeaker(Scanner keyboard, CongressoInterface congresso) throws RemoteException{
        boolean input = true;
        int day = 1, sessionNumber = 1, speakerPosition = 1;
        String speakerName = "";

        do {
            System.out.println("Giorno (1-3)");
            day = keyboard.nextInt();
            if(day >= 1 && day <= 3){
                input = false;
            }
            else{
                input = true;
                System.out.println("non valido.");
                continue;
            }

            System.out.println("Sessione (1-12)");
            sessionNumber = keyboard.nextInt();
            if(sessionNumber >= 1 && sessionNumber <= 12){
                input = false;
            }
            else {
                input = true;
                System.out.println("non valido.");
                continue;
            }

            System.out.println("Posione speaker (1-5)");
            speakerPosition = keyboard.nextInt();
            if(speakerPosition >= 1 && speakerPosition <= 5){
                input = false;
            }
            else {
                input = true;
                System.out.println("non valido.");
                continue;
            }
            keyboard.nextLine();
            System.out.println("Nome speaker");
            speakerName = keyboard.nextLine();
        }while (input);

        System.out.println(congresso.addSpeaker(day, sessionNumber, speakerPosition, speakerName)? "inserito con sucesso":"fallito.");
    }

    static void handleCalendar(Scanner keyboard, CongressoInterface congresso) throws RemoteException {
        boolean input = true;
        int day = 1;
        while (input) {
            System.out.println("Inserisci il numero di giorno: ");
            day = keyboard.nextInt();
            if (day >= 1 && day <= 3) {
                input = false;
            }

        }
        System.out.println(congresso.getCalendar(day));
    }

    public static void main(String[] args) {
        try {
            Registry registry = LocateRegistry.getRegistry(1099);
            CongressoInterface congresso = (CongressoInterface) registry.lookup("congresso");
            Scanner keyboard = new Scanner(System.in);
            while(true) {
                System.out.println(
                        "Gestione Congresso\n" +
                        "Cosa vuoi fare?\n" +
                        "1-inserire un nuovo speaker\n" +
                        "2-stampare il calendario di un giorno\n" +
                        "3-esci");
                switch (keyboard.nextInt()){
                    case 1:
                        handleNewSpeaker(keyboard, congresso);
                        break;
                    case 2:
                        handleCalendar(keyboard, congresso);
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

package server;

import shared.CongressoInterface;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class Congresso extends UnicastRemoteObject implements CongressoInterface {
    CongressoDay[] congressoDays;

    protected Congresso() throws RemoteException{
        super();
        congressoDays = new CongressoDay[3];
        for (int i = 0; i < 3; i++) {
            congressoDays[i] = new CongressoDay();
        }
    }

    public boolean addSpeaker(int day, int sessionNumber, int speakerPosition, String speakerName) throws RemoteException{
        return congressoDays[day-1].setSession(sessionNumber, speakerName, speakerPosition);
    }

    public String getCalendar(int day){
        return congressoDays[day-1].toString();
    }
}

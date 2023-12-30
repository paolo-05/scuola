package shared;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface CongressoInterface extends Remote {
    boolean addSpeaker(int day, int sessionNumber, int speakerPosition, String speakerName) throws RemoteException;
    String getCalendar(int day) throws RemoteException;
}

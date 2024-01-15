package interfaces;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface TabelloneBingo extends Remote {
    String numeriRimanenti() throws RemoteException;
    void scegliNumero(int luckyNumber, InterfacciaRisultato result) throws  RemoteException;
}

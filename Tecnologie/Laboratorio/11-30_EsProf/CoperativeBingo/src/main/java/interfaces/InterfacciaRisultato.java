package interfaces;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface InterfacciaRisultato   extends Remote {
    public void vittoria() throws RemoteException;
    public void sconfitta(int numeroVincente) throws  RemoteException;
}

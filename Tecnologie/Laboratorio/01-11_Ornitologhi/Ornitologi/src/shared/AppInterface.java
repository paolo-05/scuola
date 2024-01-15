package shared;

import java.rmi.Remote;
import java.rmi.RemoteException;


public interface AppInterface extends Remote{
    public void segnala(String nome, Coordinata coordinata) throws RemoteException;
    public String getUltimi() throws RemoteException;

   public String getZona(Coordinata coordinata, int raggio) throws RemoteException;
}

package uno;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface SumInterface extends Remote {
    int somma(int a, int b) throws RemoteException;
}

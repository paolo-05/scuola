// SumInterface.java
package due;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface SumInterface extends Remote {
    int sum() throws RemoteException;
    int getX() throws RemoteException;
    int getY() throws RemoteException;
    void setX(int x) throws RemoteException;
    void setY(int y) throws RemoteException;
}

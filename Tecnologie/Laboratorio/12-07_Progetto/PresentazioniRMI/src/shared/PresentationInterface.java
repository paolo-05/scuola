// Interfaccia per il feedback
package shared;
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface PresentationInterface extends Remote {
    void feedback(String feedback) throws RemoteException;
}

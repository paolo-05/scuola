// Interfaccia per il feedback
package shared;
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface FeedbackInterface extends Remote {
    void sendFeedback(String feedback) throws RemoteException;
}

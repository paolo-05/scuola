// Interfaccia per il servizio di presentazione

package shared;
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface PresentationServiceInterface extends Remote {
    String createPresentation(String presentationName) throws RemoteException;
    String joinPresentation(String presentationName) throws RemoteException;
    void leavePresentation(String presentationName, String clientId) throws RemoteException;
    void receiveFeedback(String presentationName, String clientId, String feedback) throws RemoteException;
    int getActivePresentationsCount() throws RemoteException;
}

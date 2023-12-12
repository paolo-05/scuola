package server;

import shared.PresentationServiceInterface;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.HashMap;
import java.util.Map;

public class PresentationService extends UnicastRemoteObject implements PresentationServiceInterface {
    private Map<String, PresentationRoom> presentationRooms = new HashMap<>();

    public PresentationService() throws RemoteException {
        super();
    }

    @Override
    public String createPresentation(String presentationName) throws RemoteException {
        PresentationRoom room = new PresentationRoom();
        presentationRooms.put(presentationName, room);
        return presentationName;
    }

    @Override
    public String joinPresentation(String presentationName) throws RemoteException {
        PresentationRoom room = presentationRooms.get(presentationName);
        if (room != null) {
            return room.addClient();
        }
        return null;
    }

    @Override
    public void leavePresentation(String presentationName, String clientId) throws RemoteException {
        PresentationRoom room = presentationRooms.get(presentationName);
        if (room != null) {
            room.removeClient(clientId);
        }
    }

    @Override
    public void receiveFeedback(String presentationName, String clientId, String feedback) throws RemoteException {
        PresentationRoom room = presentationRooms.get(presentationName);
        if (room != null) {
            room.receiveFeedback(clientId, feedback);
        }
    }

    @Override
    public int getActivePresentationsCount() throws RemoteException {
        return presentationRooms.size();
    }
}

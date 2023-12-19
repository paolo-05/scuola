package client;

import shared.PresentationInterface;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class PresentationRoom  extends UnicastRemoteObject implements PresentationInterface {
    public PresentationRoom() throws RemoteException{
        super();
    }
    @Override
    public void feedback(String feedback){
        System.out.println(feedback);
    }
}

package uno;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class AddClass extends UnicastRemoteObject implements SumInterface {
    public AddClass() throws RemoteException {
        super();
    }

    public int somma(int a, int b) throws RemoteException {
        System.out.println("Called sum");
        return a + b;
    }
}

// AddClass.java
package due;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class AddClass extends UnicastRemoteObject implements SumInterface {
    private int x;
    private int y;

    public AddClass() throws RemoteException {
        super();
        this.x = 0;
        this.y = 0;
    }

    public int sum() throws RemoteException {
        System.out.println("Called sum");
        return x + y;
    }

    public int getX() throws RemoteException {
        return x;
    }

    public int getY() throws RemoteException {
        return y;
    }

    public void setX(int x) throws RemoteException {
        this.x = x;
    }

    public void setY(int y) throws RemoteException {
        this.y = y;
    }
}

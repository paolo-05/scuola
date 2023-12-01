import java.net.MalformedURLException;
import java.rmi.AlreadyBoundException;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class Server extends UnicastRemoteObject implements CiaoInterfaccia {
    protected Server() throws RemoteException {
        super();
    }

    @Override
    public String CiaoClient(String nome) {
        String str = "Ciao sono il server " + nome;
        System.out.println("Ciao ");
        return  str;
    }

    public static void main(String[] args) {
        try {
            Naming.bind("//localhost/server", new Server());
        } catch (AlreadyBoundException | MalformedURLException | RemoteException e) {
            throw new RuntimeException(e);
        }
    }
}

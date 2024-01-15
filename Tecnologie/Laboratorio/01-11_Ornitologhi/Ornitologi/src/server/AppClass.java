package server;

import shared.AppInterface;
import shared.Coordinata;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;

public class AppClass extends UnicastRemoteObject implements AppInterface {
    ArrayList<Avvistamento> avvistamenti;
    int size = 40;


    public AppClass() throws RemoteException {
        super();
        avvistamenti = new ArrayList<>();
    }

    @Override
    public void segnala(String nome, Coordinata coordinata) throws RemoteException {
        Avvistamento a = new Avvistamento(nome, coordinata);
        avvistamenti.add(a);
    }

    @Override
    public String getUltimi() throws RemoteException {
        StringBuilder message = new StringBuilder();


        for (int i = avvistamenti.size(); i > avvistamenti.size() - 5  && i >= 0; i--) {
            message.append(i).append(avvistamenti.get(i - 1)).append("\n");
        }

        return message.toString();
    }

    @Override
    public String getZona(Coordinata coordinata, int raggio) throws RemoteException {
        StringBuilder message = new StringBuilder();

        for (int i = avvistamenti.size(); i > 0; i--) {
            if(avvistamenti.get(i-1).coordinata.sonoEntroRaggio(coordinata, raggio)){
                message.append(i).append(avvistamenti.get(i - 1)).append("\n");
            }
        }
        return message.toString();
    }
}

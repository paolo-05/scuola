package client;

import interfaces.InterfacciaRisultato;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class Risultato  extends UnicastRemoteObject implements InterfacciaRisultato {

    public Risultato() throws  RemoteException{
    }
    @Override
    public void vittoria() throws RemoteException {
        System.out.println("hai vinto!");
    }

    @Override
    public void sconfitta(int numeroVincente) throws RemoteException {
        System.out.println("hai perso, ha vinto il numero " + numeroVincente);
    }
}

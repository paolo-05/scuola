package server;

import interfaces.InterfacciaRisultato;
import interfaces.TabelloneBingo;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.Random;

public class TabelloneReale extends UnicastRemoteObject implements TabelloneBingo {
    private int sizeTabellone;
    private InterfacciaRisultato[] tabellone;
    public TabelloneReale(int sizeTabellone) throws RemoteException
    {   super();
        this.sizeTabellone = sizeTabellone;
        tabellone = new InterfacciaRisultato[sizeTabellone];
        initTabellone();
    }

    @Override
    public String numeriRimanenti() throws RemoteException {
        String result  = "";
        for( int i =0 ;i <sizeTabellone;i++){
            if(tabellone[i] == null){
                result += i+1 + " ";
            }
        }
        return result;
    }

    public synchronized void scegliNumero(int numero, InterfacciaRisultato risultato) throws RemoteException{
        tabellone[numero-1] = risultato;
        if(numeriRimanenti().isBlank()){
            notify();
        }

    }
    private void initTabellone(){
        for(int i = 0; i< sizeTabellone;i++){
            tabellone[i] = null;
        }
    }
     public synchronized void estrazione() throws RemoteException, InterruptedException {
        wait();
        Random generator = new Random();
        int numeroEstratto = generator.nextInt(0,sizeTabellone);
        tabellone[numeroEstratto].vittoria();
        for(int i = 0; i< sizeTabellone;i++){
            if(i != numeroEstratto)
                tabellone[i].sconfitta(numeroEstratto + 1);
        }

    }
}

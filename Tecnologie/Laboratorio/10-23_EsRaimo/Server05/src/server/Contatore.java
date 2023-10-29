package server;

public class Contatore {

    private int value = 0;

    public int getValue() {
        return value;
    }

    public synchronized void aumenta(int num) {
        value += num;
    }
}

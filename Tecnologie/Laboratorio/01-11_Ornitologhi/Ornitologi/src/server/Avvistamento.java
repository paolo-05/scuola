package server;

import shared.Coordinata;

import java.io.Serializable;

public class Avvistamento implements Serializable {
    String nome;
    Coordinata coordinata;

    public Avvistamento(String nome, Coordinata coordinata) {
        this.nome = nome;
        this.coordinata = coordinata;
    }

    public String getNome() {
        return nome;
    }

    public Coordinata getCoordinata() {
        return coordinata;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setCoordinata(Coordinata coordinata) {
        this.coordinata = coordinata;
    }

    public String toString(){
        return nome + "\t" + coordinata;
    }
}

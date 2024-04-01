/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package server;

import javax.xml.bind.annotation.XmlRootElement;
import java.util.ArrayList;

/**
 *
 * @author dav
 */
@XmlRootElement
public class Libreria {
    private ArrayList<Libro> elencoLibri;
    private int n_libri;
    private static Libreria singletonLibrary;
    private Libreria() throws Exception{
        if(singletonLibrary != null){
            throw new Exception("singleton problem!");
        }
            elencoLibri= new ArrayList<Libro>();
            System.out.println("creato nuovo !");
            n_libri = 0;
    }
       
    public static Libreria getLibreria(){
        if(singletonLibrary == null){
            try{
                singletonLibrary = new Libreria();
            }catch(Exception e){
                System.out.println("very strange exception (singleton)");
            }
        } 
        return singletonLibrary;
 
    }
    
    public synchronized int addLibro(Libro libro){
        elencoLibri.add(libro);
        n_libri++;
        return n_libri-1;
    }
    
    public synchronized Libro getLibro(int id){
        if(id <= n_libri)
            return elencoLibri.get(id);
        return null;
    }

    public ArrayList<Libro> getLibri() {
        return elencoLibri;
    }
}

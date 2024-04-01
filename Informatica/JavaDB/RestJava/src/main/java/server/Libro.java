/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package server;

import javax.xml.bind.annotation.XmlRootElement;

/**
 *
 * @author dav
 */
@XmlRootElement
public class Libro {
    String autore;
    String titolo;
    String casaEditrice;
    
    public Libro(){}
    
    public String getAutore(){
        return autore;
    }
    
    public String getTitolo(){
        return titolo;
    }
    
    public String getCasaEditrice(){
        return casaEditrice;
    }
    
    public void setAutore(String autore){
        this.autore = autore;
    }
    
    public void setTitolo(String titolo){
        this.titolo = titolo;
    }
    
     public void setCasaEditrice(String casaEditrice){

        this.casaEditrice = casaEditrice;
    }
    
    
    
    
}

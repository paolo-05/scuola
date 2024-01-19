package provadb;

import java.sql.*;
import java.util.Scanner;

public class Northwind2 {
    public static void main(String[] args) {
        try {
            
            // legge dati del nuovo record
             Scanner sc = new Scanner(System.in);
                System.out.println("Inserisci i dati del nuovo cliente:");
                System.out.print("ID: ");
                String id = sc.nextLine();
                System.out.print("Nome: ");
                String name = sc.nextLine();
                System.out.print("Città: ");
                String city = sc.nextLine();
                System.out.print("Paese: ");
                String country = sc.nextLine();

            // Caricamento del driver MySQL
            Class.forName("com.mysql.jdbc.Driver");

            // Connessione al database Northwind
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/northwind", "root", "PasswordRoot");

            // Creazione dell'oggetto per l'esecuzione della query
            Statement st = con.createStatement();
            
            // inserimento nella tabella
            String sql = "INSERT INTO customers (CustomerID, CompanyName, City, Country) " +
                   "VALUES ('" + id + "', '" + name + "', '" + city + "', '" + country + "')";
            int nrow= st.executeUpdate(sql);
            if (nrow==1)
                System.out.println("Cliente inserito con successo!");
            else
                System.out.println("Problemi di inserimento!");
            // Chiusura della connessione
            con.close();

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}

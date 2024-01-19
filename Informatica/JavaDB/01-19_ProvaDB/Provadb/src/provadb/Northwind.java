import java.sql.*;

public class Northwind {
    public static void main(String[] args) {
        try {
            // Caricamento del driver MySQL
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Connessione al database Northwind
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/northwind", "root", "PasswordRoot");

            String paese = "Italy"; // letto da qualche parte
                    
            // Creazione della query per selezionare tutti i dati della tabella customers
            //String query = "SELECT * FROM customers WHERE Country='" + paese+"'";
            //System.out.println(query);

            // Creazione dell'oggetto per l'esecuzione della query
            //Statement st = con.createStatement();
            
            // Query con parametri
            String query = "SELECT * FROM customers where Country=?";
            PreparedStatement st = con.prepareStatement(query);
            st.setString(1, paese);
            ResultSet rs = st.executeQuery();

            // Esecuzione della query
            //ResultSet rs = st.executeQuery(query);

            // Stampa dei risultati
            while (rs.next()) {
                System.out.println("Customer ID: " + rs.getString("CustomerID"));
                System.out.println("Company Name: " + rs.getString("CompanyName"));
                System.out.println("Contact Name: " + rs.getString("ContactName"));
                System.out.println("Contact Title: " + rs.getString("ContactTitle"));
                System.out.println("Address: " + rs.getString("Address"));
                System.out.println("City: " + rs.getString("City"));
                System.out.println("Region: " + rs.getString("Region"));
                System.out.println("Postal Code: " + rs.getString("PostalCode"));
                System.out.println("Country: " + rs.getString("Country"));
                System.out.println("Phone: " + rs.getString("Phone"));
                System.out.println("Fax: " + rs.getString("Fax"));
                System.out.println("\n");
            }

            // Chiusura della connessione
            con.close();

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}

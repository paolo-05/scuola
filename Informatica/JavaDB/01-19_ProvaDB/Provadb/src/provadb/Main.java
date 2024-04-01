import java.sql.*;
import javax.swing.*;
import javax.swing.table.*;

public class Main extends JFrame {
  // Costruttore
  public Main() {
    // Imposta il titolo della finestra
    setTitle("Tabella Clienti");

    // Imposta le dimensioni della finestra
    setSize(600, 400);

    // Imposta la posizione della finestra
    setLocationRelativeTo(null);

    // Imposta il comportamento alla chiusura della finestra
    setDefaultCloseOperation(EXIT_ON_CLOSE);

    try {
      // Carica il driver MySQL
      Class.forName("com.mysql.cj.jdbc.Driver");

      // Crea la connessione al database
      Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/northwind", "root", "PasswordRoot");

      // Crea un oggetto Statement per eseguire una query
      Statement stmt = con.createStatement();

      // Esegue la query per selezionare i dati dalla tabella clienti
      ResultSet rs = stmt.executeQuery("SELECT ProductName as Prodotto, UnitPrice as Prezzo FROM products");

      // Crea un oggetto DefaultTableModel per contenere i dati
      DefaultTableModel model = new DefaultTableModel();

      // Crea un oggetto JTable per visualizzare i dati
      JTable table = new JTable(model);

      // Aggiunge le colonne al modello della tabella
      ResultSetMetaData metaData = rs.getMetaData();
      int columnCount = metaData.getColumnCount();
      for (int column = 1; column <= columnCount; column++) {
        model.addColumn(metaData.getColumnName(column));
      }

      // Aggiunge le righe al modello della tabella
      while (rs.next()) {
        Object[] row = new Object[columnCount];
        for (int i = 0; i < row.length; i++) {
          row[i] = rs.getObject(i + 1);
        }
        model.addRow(row);
      }

      // Aggiunge la tabella al pannello di contenuto della finestra
      add(new JScrollPane(table));

      // Chiude la connessione al database
      con.close();
    } catch (Exception e) {
      JOptionPane.showMessageDialog(this, e.getMessage(), "Errore", JOptionPane.ERROR_MESSAGE);
    }
  }

  public static void main(String[] args) {
    // Crea un oggetto Main e lo rende visibile
    Main main = new Main();
    main.setVisible(true);
  }
}

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

import java.sql.*;
import java.util.HashMap;
/**
 *
 * @author paolo
 */
public class DatabaseHandler {
    private static final String JDBC_URL = "jdbc:mysql://localhost:3306/magazzino";
    private static final String USERNAME = "root";
    private static final String PASSWORD = "PasswordRoot";

    private Connection connection;

    public DatabaseHandler() {
        try {
            // Load the JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");
            // Establish the database connection
            connection = DriverManager.getConnection(JDBC_URL, USERNAME, PASSWORD);
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }
    }

    public void closeConnection() {
        try {
            if (connection != null && !connection.isClosed()) {
                connection.close();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void insertSupplier(String nome, String citta) {
        String query = "INSERT INTO fornitori (Nome, Citta) VALUES (?, ?)";
        executeUpdate(query, nome, citta);
    }

    public void insertProduct(String nome, double prezzo, int codForn) {
        String query = "INSERT INTO prodotti (Nome, Prezzo, CodForn) VALUES (?, ?, ?)";
        executeUpdate(query, nome, prezzo, codForn);
    }

    public void insertMovement(String data, String tipo, int quantita, int codProd) {
        String query = "INSERT INTO movimenti (Data, Tipo, Quantita, CodProd) VALUES (?, ?, ?, ?)";
        executeUpdate(query, data, tipo, quantita, codProd);
    }

    public HashMap<Integer, Integer> getCurrentStock() {
        HashMap<Integer, Integer> stockMap = new HashMap<>();
        String query = "SELECT CodProd, SUM(CASE WHEN Tipo = 'Carico' THEN Quantita ELSE -Quantita END) AS Giacenza " +
                "FROM movimenti GROUP BY CodProd";
        try (ResultSet resultSet = executeQuery(query)) {
            while (resultSet.next()) {
                int codProd = resultSet.getInt("CodProd");
                int giacenza = resultSet.getInt("Giacenza");
                stockMap.put(codProd, giacenza);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return stockMap;
    }

    public ResultSet getMovementsForProduct(int codProd, String startDate, String endDate) {
        String query = "SELECT * FROM movimenti WHERE CodProd = ? AND Data BETWEEN ? AND ?";
        return executeQuery(query, codProd, startDate, endDate);
    }

    private void setParameters(PreparedStatement preparedStatement, Object... parameters) throws SQLException {
        for (int i = 0; i < parameters.length; i++) {
            preparedStatement.setObject(i + 1, parameters[i]);
        }
    }

    private ResultSet executeQuery(String query, Object... parameters) {
        ResultSet resultSet = null;
        try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
            setParameters(preparedStatement, parameters);
            resultSet = preparedStatement.executeQuery();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return resultSet;
    }

     private int executeUpdate(String query, Object... parameters) {
        int rowsAffected = 0;
        try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
            setParameters(preparedStatement, parameters);
            rowsAffected = preparedStatement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return rowsAffected;
    }
}

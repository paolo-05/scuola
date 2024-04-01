/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/WebServices/GenericResource.java to edit this template
 */
package REST_5IC;

import javax.ws.rs.*; 
import javax.ws.rs.core.*;
import java.sql.*;

@Path("dischi")
public class Disco{
  // stringhe di connessione al database MySql
  private final String CONNECTION_DB = "jdbc:mysql://localhost:3306/";   
  private final String CONNECTION_CLASS = "com.mysql.cj.jdbc.Driver";
  private final String DB_NAME = "mediateca";
  private final String DB_USERNAME = "root";
  private final String DB_PASSWORD = "PasswordRoot";
  // stringhe di comunicazione esito esecuzione delle query SQL     
  private final String SQL_INSERT_CORRECT = "{\"message\": \"Record inserito correttamente.\", \"status\": \"201\"}";
  private final String SQL_UPDATE_CORRECT = "\"{\"message\": \"Record aggiornato correttamente.\", \"status\": \"200\"}";
  private final String SQL_DELETE_CORRECT = "{\"message\": \"Disco cancellato correttamente.\", \"status\": \"200\"}";
  // definizione gestione personalizzata delle eccezioni        
  private final PersonalExceptions persExc;
   
  public Disco(){
    persExc = new PersonalExceptions();
  }

  /**
   * Metodo: getDataInJSON
   * Gestisce il ricevimento di un URL utilizzando il metodo GET.
   * Viene utilizzato per restituire tutti i dati del DB.
   * Operazione: READ.
   * @since 1.0
   * @return JSONDatabase (String) -> formato JSON
   * @throws java.lang.Exception;
   */
  @GET
  @Produces(MediaType.APPLICATION_JSON)
  public String getDataInJSON() throws Exception
  {
    String queryString = "SELECT * FROM dischi";
    String JSONDatabase = selectDataFromDB(DB_NAME, DB_USERNAME, DB_PASSWORD, queryString);
    return JSONDatabase;
  }
   
  /**
  * Metodo: getDataInJSON
  * Gestisce il ricevimento di un URL utilizzando il metodo GET.
  * Viene utilizzato per restituire uno o alcuni dati dal DB in base al parametro.
  * Operazione: READ.
  * @param parametro(String) -> Può essere riferito a qualunque attributo.
  * @since 1.0
  * @return JSONDatabase (String) -> formato JSON
  * @throws Exception
  */
  @GET
  @Path("{parameter}")
  @Produces(MediaType.APPLICATION_JSON)
  public String getDataInJSON(@PathParam("parameter") String parametro) throws Exception
  {
    String queryString = "SELECT * FROM dischi "
      + "WHERE NRcatalogo LIKE \"%" + parametro + "%\""
      + "OR Genere LIKE \"%" + parametro + "%\""
      + "OR Interprete LIKE \"%" + parametro + "%\""
      + "OR Titolo LIKE \"%" + parametro + "%\""
      + "OR Etichetta  LIKE \"%" + parametro + "%\"";
    String JSONDatabase = selectDataFromDB(DB_NAME, DB_USERNAME, DB_PASSWORD, queryString);
    return JSONDatabase;
  }
   
  /**
   * Metodo: createDataInJSON
   * Inserisce un nuovo record mediante richiesta POST e i parametri passati.
   * Operazione: CREATE.
   * @param NRcatalogo
   * @param genere
   * @param interprete
   * @param titolo
   * @param etichetta
   * @since 1.1
   * @exception SQLException
   * @return JSONMessage -> Esito della creazione del record.
   */
  @POST
  @Path("{NRcatalogo}/{Genere}/{Interprete}/{Titolo}/{Etichetta}")
  @Produces(MediaType.APPLICATION_JSON)
  public String createDataInJSON(@PathParam("NRcatalogo") String NRcatalogo, @PathParam("Genere") String genere,
    @PathParam("Interprete") String interprete, @PathParam("Titolo") String titolo, @PathParam("Etichetta") String etichetta) 
                                                                                                                    throws Exception
  {
    String queryString = "INSERT INTO dischi(NRcatalogo, Genere, Interprete, Titolo, Etichetta) "
      + "VALUES (\"" + NRcatalogo + "\",\"" + genere + "\",\"" + interprete + "\",\"" + titolo + "\",\"" + etichetta + "\")";
    String JSONMessage = createDataInDB(DB_NAME, DB_USERNAME, DB_PASSWORD, queryString);
    return JSONMessage;
  }
  
  /**
   * Metodo: updateDataInJSON
   * Aggiorna i dati presenti nel database mediante il metodo PUT.
   * Il riferimento è alla chiave primaria, mentre gli altri parametri sono quelli aggiornati.
   * Operazione: UPDATE.
   * @param NRcatalogo (String) -> Serve come riferimento al record da aggiornare; immodificabile.
   * @param genere (String)
   * @param interprete (String)
   * @param titolo (String)
   * @param etichetta
   * @throws java.lang.Exception
   * @return JSONMessage (String) 
   */
  @PUT
  @Path("{NRcatalogo}/{Genere}/{Interprete}/{Titolo}/{Etichetta}")
  @Produces(MediaType.APPLICATION_JSON)
  public String updateDataInJSON(@PathParam("NRcatalogo") String NRcatalogo, @PathParam("Genere") String genere,
    @PathParam("Interprete") String interprete, @PathParam("Titolo") String titolo, @PathParam("Etichetta") String etichetta) 
                                                                                                                    throws Exception
  {
    String queryString = "UPDATE dischi SET Genere=\"" + genere + "\", Interprete=\"" + interprete + "\","
      +  " Etichetta=\"" + etichetta + "\", Titolo=\"" + titolo +"\" WHERE NRcatalogo=\"" + NRcatalogo +"\"";
    String JSONMessage = updateDataInDB(DB_NAME, DB_USERNAME, DB_PASSWORD, queryString);
      return JSONMessage;
  }
  
  /**
   * Metodo: deleteDataInJSON
   * Elimina il record con chiave primaria NRcatalogo passata come parametro.
   * Operazione: DELETE.
   * @param NRcatalogo
   * @throws java.lang.Exception
   * @return JSONMessage (String)
   */
  @DELETE
  @Path("{NRcatalogo}")
  @Produces(MediaType.APPLICATION_JSON)
  public String deleteDataInJSON(@PathParam("NRcatalogo") String NRcatalogo) throws Exception
  {
    String queryString = "DELETE FROM dischi WHERE NRcatalogo=\"" + NRcatalogo + "\"";
    String JSONMessage = deleteDataInDB(DB_NAME, DB_USERNAME, DB_PASSWORD, queryString);
    return JSONMessage;
  }
  
  // -------------------------------------------------
  // Metodi accessori e privati per le operazioni CRUD
  // -------------------------------------------------
  // selectDataFromDB -> (READ) operazione di selezione, composizione del JSON e restituizione del risultato.
  // createDataInDB -> (CREATE) operazione di creazione di un nuovo record.
  // updateDataInDB -> (UPDATE) operazione di aggiornamento di un record esistente.
  // deleteDataInDB -> (DELETE) operazione di eliminazione di un record esistente.
  // -------------------------------------------------
   
  // Operazione: READ
  private String selectDataFromDB(String nomeDB, String username, String password, String queryString) {
    ResultSet rs;
    String connectionString, resultString = "";
    try {
      Class.forName(CONNECTION_CLASS);                       // carichiamo il driver
    } 
    catch (ClassNotFoundException e) {
      resultString = persExc.getClassNotFoundException();   
    }
    Connection connection = null;  
    try {                                                    // ci connettiamo al database
      connectionString = CONNECTION_DB + nomeDB;
      connection = DriverManager.getConnection(connectionString, username, password);
      Statement stm = connection.createStatement();
      rs = stm.executeQuery(queryString);                    // eseguiamo la query
      resultString = "{\"records\":[";                       // prepariamo l'array di risposta
      while(rs.next()) { 
        resultString += "{\"NRcatalogo\": " + "\"" + rs.getString("NRcatalogo") + "\""
         + ", \"Genere\": " + "\"" + rs.getString("Genere") + "\"" + ", \"Interprete\": " + "\"" + rs.getString("Interprete") + "\""
         + ", \"Titolo\": " + "\"" + rs.getString("Titolo") + "\"" + ", \"Etichetta\": " + "\"" + rs.getString("Etichetta")+ "\"},";
      }
      if(resultString.equals("{\"records\":[")) {            // nessun record trovato
        resultString = persExc.getSQLNoResultFound();
      }
      else {
        resultString = resultString.substring(0, resultString.length() - 1) + "]}";
      }
    } 
    catch (SQLException e) {
      resultString = persExc.getSQLExceptionRequest();       // gestione delle eccezioni
    } 
    catch (Exception e) {
      resultString = persExc.getExceptionGeneric();
    }
    finally {                                                // chiusura connessione 
      try {
	      if (connection != null) connection.close(); }
      catch (SQLException e) {
        resultString = persExc.getSQLExceptionClosing();
      }
    }
    return resultString;
  }
   
  // Operazione: CREATE
  private String createDataInDB(String nomeDB, String username, String password, String queryString)
  {
    String connectionString, resultString = "";
    try {
      Class.forName(CONNECTION_CLASS);
    } 
    catch (ClassNotFoundException e) {
     resultString = persExc.getClassNotFoundException();
    }
    Connection connection = null;
    try {
      connectionString = CONNECTION_DB + nomeDB;
      connection = DriverManager.getConnection(connectionString, username, password);
      Statement stm = connection.createStatement();
      int executeUpdate = stm.executeUpdate(queryString);
      if (executeUpdate <= 0) {
        resultString = persExc.getSQLCannotInsert();
      }
      else {
        resultString = SQL_INSERT_CORRECT;
      }
    } 
    catch (SQLException e) {
      resultString = persExc.getSQLExceptionRequest();
    } 
    catch (Exception e) {
      resultString = persExc.getExceptionGeneric();
    }
    finally {
      try {
	    	if (connection != null)
          connection.close();
      }
      catch (SQLException e) {
        resultString = persExc.getSQLExceptionClosing();
      }
    }
    return resultString;
  }
    
  // Operazione: UPDATE
  private String updateDataInDB(String nomeDB, String username, String password, String queryString)
  {
    String connectionString, resultString = "";
    try {
      Class.forName(CONNECTION_CLASS);
    } 
    catch (ClassNotFoundException e) {
      resultString = persExc.getClassNotFoundException();
      // resultString = Response.Status.INTERNAL_SERVER_ERROR.toString();
    }
    Connection connection = null;
    try {
      connectionString = CONNECTION_DB + nomeDB;
      connection = DriverManager.getConnection(connectionString, username, password);
      Statement stm = connection.createStatement();
      int executeUpdate = stm.executeUpdate(queryString);
      if (executeUpdate <= 0) {
        resultString = persExc.getSQLCannotUpdate();
      }
      else {
        resultString = SQL_UPDATE_CORRECT;
      }
    } 
    catch (SQLException e) {
      resultString = persExc.getSQLExceptionGeneric();
    } 
    catch (Exception e) {
      resultString = persExc.getExceptionGeneric();
    }
    finally {
      try {
    		if (connection != null)
          connection.close();
        }
      catch (SQLException e) {
        resultString = persExc.getSQLExceptionClosing();
      }
    }
    return resultString;
  }
    
  // Operazione: DELETE
  private String deleteDataInDB(String nomeDB, String username, String password, String queryString)
  {
    String connectionString, resultString = "";
    try {
        Class.forName(CONNECTION_CLASS);
    } 
    catch (ClassNotFoundException e) {
      resultString = persExc.getClassNotFoundException();
      // resultString = Response.Status.INTERNAL_SERVER_ERROR.toString();
    }
    Connection connection = null;
    try {
      connectionString = CONNECTION_DB + nomeDB;
      connection = DriverManager.getConnection(connectionString, username, password);
      Statement stm = connection.createStatement();
      if (!stm.execute(queryString)) {
        resultString = SQL_DELETE_CORRECT;
      }
      else {
        resultString = persExc.getSQLCannotDelete();
      }
    } 
    catch (SQLException e) {
      resultString = persExc.getSQLExceptionGeneric();
    } 
    catch (Exception e) {
      resultString = persExc.getExceptionGeneric();
    }
    finally {
      try {
	    	if (connection != null)
          connection.close();
        }
      catch (SQLException e) {
        resultString = persExc.getSQLExceptionClosing();
      }
    }
    return resultString;
  }
}
 


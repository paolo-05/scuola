/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package exception;
package REST_5IC;

/**
 *
 * @author matte
 */
public class PersonalExceptions extends Exception
{
    private final String EXCEPTION_GENERIC = "{\"message\": \"Eccezione: Exception.\", \"status\": \"503\"}";
    private final String CLASS_NOT_FOUND_EXCEPTION = "{\"message\": \"Eccezione: ClassNotFound.\", \"status\": \"503\"}";
    private final String SQL_EXCEPTION_GENERIC = "{\"message\": \"Eccezione: SQLException.\", \"status\": \"503\"}";
    private final String SQL_EXCEPTION_REQUEST = "{\"message\": \"Eccezione SQLException nella richiesta.\", \"status\": \"503\"}";
    private final String SQL_EXCEPTION_CLOSING = "{\"message\": \"Eccezione SQLException nella chiusura.\", \"status\": \"503\"}";
    private final String SQL_NO_RESULT_FOUND = "{\"message\": \"Nessun risultato ottenuto.\", \"status\": \"404\"}";
    private final String SQL_CANNOT_INSERT = "{\"message\": \"Impossibile eseguire l'inserimento del nuovo record.\", \"status\": \"503\"}";
    private final String SQL_CANNOT_UPDATE = "{\"message\": \"Impossibile eseguire l'aggiornamento del libro.\", \"status\": \"503\"}";
    private final String SQL_CANNOT_DELETE = "{\"message\": \"Impossibile cancellare libro.\", \"status\": \"503\"}";
    
    public PersonalExceptions() {}
    
    public String getExceptionGeneric() { return EXCEPTION_GENERIC; }
    public String getClassNotFoundException() { return CLASS_NOT_FOUND_EXCEPTION; }
    public String getSQLExceptionGeneric() { return SQL_EXCEPTION_GENERIC; }
    public String getSQLExceptionRequest() { return SQL_EXCEPTION_REQUEST; }
    public String getSQLExceptionClosing() { return SQL_EXCEPTION_CLOSING; }
    public String getSQLNoResultFound() { return SQL_NO_RESULT_FOUND; }
    public String getSQLCannotInsert() { return SQL_CANNOT_INSERT; }
    public String getSQLCannotUpdate() { return SQL_CANNOT_UPDATE; }
    public String getSQLCannotDelete() { return SQL_CANNOT_DELETE; }
}

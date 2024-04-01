package client;

import com.fasterxml.jackson.databind.JsonSerializable;
import com.fasterxml.jackson.databind.jsonFormatVisitors.JsonObjectFormatVisitor;
import com.fasterxml.jackson.databind.util.JSONPObject;
import com.google.gson.Gson;
import org.glassfish.jersey.client.ClientResponse;
import org.glassfish.jersey.client.JerseyClient;
import org.glassfish.jersey.client.JerseyClientBuilder;
import org.json.JSONObject;
import server.Libro;

import javax.ws.rs.client.Client;
import javax.ws.rs.client.Entity;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import java.lang.reflect.Type;
import java.net.URI;
import java.util.ArrayList;
import com.google.gson.reflect.TypeToken;
import java.util.LinkedHashMap;

public class Main {
    static final Client client = JerseyClientBuilder.newClient();
    static final URI hostUri = URI.create("http://localhost:50555");
    public static void main(String[] args) {
        Response getResponse  = getRequest("/books");
        String  risposta = getResponse.readEntity(String.class);
        System.out.println(risposta);

    }
     public static Response getRequest(String path){
        return client.target(hostUri)
                .path(path)
                .request(MediaType.APPLICATION_JSON)
                .get();
    } public static Response postRequest(String path, Object argument){
        return   client.target(hostUri)
                .path(path)
                .request(MediaType.APPLICATION_JSON)
                .post(Entity.entity(argument,MediaType.APPLICATION_JSON));
    }
}

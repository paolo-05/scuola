    /*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package server;

import java.net.URI;
import java.util.ArrayList;
import javax.ws.rs.*;
import javax.ws.rs.core.*;

/**
 *
 * @author dav
 */
@Path("/books")
public class RestResources{
    private final Libreria restLibrary = Libreria.getLibreria();

    @GET
    @Produces("application/json")
    public Response getBooks(@DefaultValue("") @QueryParam("author")
                                 String author){
        if(author.isEmpty()){
            return Response.ok(restLibrary.getLibri()).build();
        }
        ArrayList<Libro> authorLibrary = new ArrayList<>();
        for (Libro libro: restLibrary.getLibri()
             ) {
            if(libro.autore.equals(author)) {
                authorLibrary.add(libro);
            }
        }
        return Response.ok(authorLibrary).build();
    }
    
    @GET
    @Produces("application/json")
    @Path("/book/{id}")
    public Response getBook(@PathParam("id") int id){
        Libro targetBook = restLibrary.getLibro(id);
        if(targetBook != null){
            return Response.ok(restLibrary.getLibro(id)).build();
        }
        return Response.status(Response.Status.NOT_FOUND).build();
    }
    
    @POST
    @Consumes("application/json")
    @Produces("application/json")
    @Path("/book")
    public Response createBook( Libro libro){
        int id = restLibrary.addLibro(libro);
        String pathResources = "books/book/" + id;
        URI destinationUri = URI.create(pathResources);
        return Response.created(destinationUri).build();
    }
}

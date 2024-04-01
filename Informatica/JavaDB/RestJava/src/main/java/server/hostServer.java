    /*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package server;

import java.io.IOException;
import java.net.URI;
import org.glassfish.grizzly.http.server.HttpServer;
import org.glassfish.jersey.grizzly2.httpserver.GrizzlyHttpServerFactory;
import org.glassfish.jersey.server.ResourceConfig;

/**
 *
 * @author dav
 */
public class hostServer {

    public static void main(String[] args) throws IOException {
        URI ServerAddress = URI.create("http://localhost:50555/");
        HttpServer server = GrizzlyHttpServerFactory.createHttpServer( //
                ServerAddress,new ResourceConfig(RestResources.class));
        server.start();
        while(true);
    }
}

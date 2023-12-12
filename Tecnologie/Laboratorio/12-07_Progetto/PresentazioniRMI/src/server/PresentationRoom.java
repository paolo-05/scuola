package server;

import java.util.HashSet;
import java.util.Set;

public class PresentationRoom {
    private Set<String> clients = new HashSet<>();

    public String addClient() {
        String clientId = generateClientId();
        clients.add(clientId);
        return clientId;
    }

    public void removeClient(String clientId) {
        clients.remove(clientId);
    }

    public void receiveFeedback(String clientId, String feedback) {
        System.out.println("Feedback da client " + clientId + ": " + feedback);
    }

    private String generateClientId() {
        // Implement your logic for generating unique client IDs
        return "Client" + System.currentTimeMillis();
    }
}

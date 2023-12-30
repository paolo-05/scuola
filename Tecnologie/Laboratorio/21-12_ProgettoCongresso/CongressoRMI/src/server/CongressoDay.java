package server;

import java.util.Arrays;

public class CongressoDay {
    private CongressoSession[] congressoSessions;

    public CongressoDay(){
        congressoSessions = new CongressoSession[12];
        for (int i = 0; i < 12; i++) {
            congressoSessions[i] = new CongressoSession();
        }
    }

    public boolean setSession(int sessionNumber, String speakerName, int speakerPosition){
        return congressoSessions[sessionNumber-1].setSpeaker(speakerName, speakerPosition);
    }

    @Override
    public String toString() {
        StringBuilder message = new StringBuilder();
        message.append("S\t\tSP1\t\tSP2\t\tSP3\t\tSP4\t\tSP5\n");
        for (int i = 0; i < congressoSessions.length; i++) {
            message.append("S").append(i + 1).append("\t\t").append(congressoSessions[i]).append("\n");
        }
        return message.toString();
    }
}

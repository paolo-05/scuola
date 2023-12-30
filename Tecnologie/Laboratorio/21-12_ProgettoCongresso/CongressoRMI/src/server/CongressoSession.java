package server;

public class CongressoSession {
    private String[] speakers;

    public CongressoSession(){
        speakers = new String[5];
        for (int i = 0; i < 5; i++) {
            speakers[i] = "";
        }
    }

    public boolean setSpeaker(String speakerName, int speakerPosition){
        if(speakers[speakerPosition-1].isEmpty()){
            speakers[speakerPosition-1] = speakerName;
           return true;
        }
        return false;
    }

    @Override
    public String toString(){
        StringBuilder message = new StringBuilder();
        for (int i = 0; i < 5; i++) {
            message.append(speakers[i].isEmpty() ? "vuoto\t\t" : speakers[i] + "\t\t");
        }
        return message.toString();
    }
}

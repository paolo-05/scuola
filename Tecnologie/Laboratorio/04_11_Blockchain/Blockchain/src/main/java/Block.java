import java.util.Date;

public class Block {
    public String hash;
    public String previousHash;
    private final String data;
    private final long timeStamp;
    private int nounce;

    public Block(String data, String previousHash){
        this.data = data;
        this.previousHash = previousHash;
        this.timeStamp = new Date().getTime();
        this.nounce = 0; // initialize nounce to 0
        this.hash = calculateHash();
    }

    public String calculateHash(){
        return crypt.sha256(previousHash + timeStamp + nounce + data);
    }

    public void mineBlock(int difficulty) {
        String target = new String(new char[difficulty]).replace('\0', '0'); //Create a string with difficulty * "0" 
        while(!hash.substring(0, difficulty).equals(target)) {
            nounce++;
            hash = calculateHash();
        }
    }
}
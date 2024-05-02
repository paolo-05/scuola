import java.util.ArrayList;

public class Blockchain {
    public ArrayList<Block> chain;
    public int difficulty;

    public Blockchain(int difficulty) {
        this.chain = new ArrayList<>();
        this.difficulty = difficulty;
        // Create the first block manually
        Block genesisBlock = new Block("Genesis Block", "0");
        genesisBlock.mineBlock(difficulty);
        chain.add(genesisBlock);
    }

    public void addBlock(Block newBlock) {
        newBlock.mineBlock(this.difficulty);
        this.chain.add(newBlock);
    }

    public boolean validateChain() {
        for(int i = 1; i < chain.size(); i++) {
            Block currentBlock = chain.get(i);
            Block previousBlock = chain.get(i-1);

            // Compare registered hash and calculated hash
            if(!currentBlock.hash.equals(currentBlock.calculateHash()) ){
                return false;
            }

            // Compare previous hash and registered previous hash
            if(!currentBlock.previousHash.equals(previousBlock.hash)) {
                return false;
            }
        }
        return true;
    }
}
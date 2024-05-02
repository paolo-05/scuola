public class Chain {
    public static void main(String[] args) {
        // Create a new blockchain with difficulty 1
        Blockchain blockchain = new Blockchain(1);

        // Add blocks to the blockchain
        blockchain.addBlock(new Block("Block 1", blockchain.chain.getLast().hash));
        blockchain.addBlock(new Block("Block 2", blockchain.chain.getLast().hash));

        // Validate the blockchain
        System.out.println("Blockchain is Valid: " + blockchain.validateChain());
    }
}
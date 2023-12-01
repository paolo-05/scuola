import java.rmi.Naming;

public class Client {

    public static void main(String[] args) {
        try {
            CiaoInterfaccia lookUp = (CiaoInterfaccia) (Naming.lookup("localhost/server"));
            String s = lookUp.CiaoClient("Client Paolo");
            System.out.println(s);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}

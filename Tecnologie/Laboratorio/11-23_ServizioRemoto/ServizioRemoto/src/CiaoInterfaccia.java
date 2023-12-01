import java.rmi.Remote;

public interface CiaoInterfaccia extends Remote {
    public String CiaoClient(String nome) throws Exception;
}

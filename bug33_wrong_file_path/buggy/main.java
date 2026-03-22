import java.io.FileInputStream;
import java.io.IOException;

public class main {
    public static void main(String[] args) {
        String path = "/nonexistent/path/data.bin";
        try {
            FileInputStream f = new FileInputStream(path);
        } catch (IOException e) {
            throw new RuntimeException("FileNotFoundError: [Errno 2] No such file or directory: '/nonexistent/path/data.bin'", e);
        }
    }
}

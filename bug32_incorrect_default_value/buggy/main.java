import java.nio.ByteBuffer;
import java.util.Base64;

public class main {
    public static void main(String[] args) {
        long[] data = new long[10];
        for (int i = 0; i < 10; i++) {
            data[i] = 0x1A2BL << i;
        }
        throw new IllegalArgumentException("TypeError: unsupported operand type(s) for ^=: 'NoneType' and 'int'");
    }
}

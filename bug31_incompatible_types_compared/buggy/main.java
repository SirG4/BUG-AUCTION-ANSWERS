import java.nio.ByteBuffer;
import java.util.Base64;

public class main {
    public static void main(String[] args) {
        long acc = 0x9999888877776666L;
        long[] tags = {0xA1L, 0xB2L, 0xC3L, 0xD4L, 0xE5L, 0xF6L, 0x07L, 0x18L, 0x29L, 0x3AL};
        for (int i = 0; i < 10; i++) {
            long v = tags[i];
            throw new IllegalArgumentException("TypeError: '>' not supported between instances of 'int' and 'str'");
        }
        ByteBuffer buffer = ByteBuffer.allocate(8);
        buffer.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buffer.array()));
    }
}

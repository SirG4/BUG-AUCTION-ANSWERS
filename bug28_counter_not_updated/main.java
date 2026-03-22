import java.nio.ByteBuffer;
import java.util.Base64;

public class main {
    public static void main(String[] args) {
        long acc = 0xAAAABBBBCCCCDDDDL;
        long counter = 0;
        for (int i = 0; i < 10; i++) {
            acc ^= counter * 0x9E3779B97F4A7C15L;
            long shiftLeft = counter % 17 + 1;
            long shiftRight = 63 - (counter % 17);
            acc = (acc << shiftLeft) | (acc >>> shiftRight);
            acc *= 0xBF58476D1CE4E5B9L;
        }
        if (counter == 0) {
            throw new IllegalArgumentException("ValueError: counter was never updated: loop used constant 0 throughout");
        }
        ByteBuffer buffer = ByteBuffer.allocate(8);
        buffer.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buffer.array()));
    }
}

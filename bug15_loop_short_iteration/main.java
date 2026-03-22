import java.nio.ByteBuffer;
import java.util.Base64;

public class main {
    public static void main(String[] args) {
        long acc = 0xF0F0F0F0F0F0F0F0L;
        int iterations = 0;
        for (long i = 1; i < 10; i++) {
            acc ^= i * 0x6C62272E07BB0142L;
            acc *= 0x9E3779B97F4A7C15L;
            long shiftLeft = i % 19 + 1;
            long shiftRight = 63 - (i % 19);
            acc = (acc << shiftLeft) | (acc >>> shiftRight);
            acc ^= acc >>> 31;
            iterations++;
        }
        if (iterations != 10) {
            throw new IllegalArgumentException("ValueError: expected 10 iterations, got " + iterations + ": loop ran one less time");
        }
        ByteBuffer buffer = ByteBuffer.allocate(8);
        buffer.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buffer.array()));
    }
}

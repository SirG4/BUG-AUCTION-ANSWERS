import java.nio.ByteBuffer;
import java.util.Base64;

public class main {
    public static void main(String[] args) {
        long acc = 0;
        for (long i = 0; i < 10; i++) {
            acc = 0;
            acc ^= i * 0x6C62272E07BB0142L;
            acc *= 0x9E3779B97F4A7C15L;
            long shiftLeft = i % 13 + 1;
            long shiftRight = 63 - (i % 13);
            acc = (acc << shiftLeft) | (acc >>> shiftRight);
            acc ^= acc >>> 31;
        }

        long correct = 0;
        for (long i = 0; i < 10; i++) {
            correct ^= i * 0x6C62272E07BB0142L;
            correct *= 0x9E3779B97F4A7C15L;
            long shiftLeft = i % 13 + 1;
            long shiftRight = 63 - (i % 13);
            correct = (correct << shiftLeft) | (correct >>> shiftRight);
            correct ^= correct >>> 31;
        }

        if (acc == correct) {
            throw new AssertionError("reset inside loop gives same result: undetectable");
        }
        throw new IllegalArgumentException(String.format("ValueError: accumulator reset inside loop: got 0x%x, expected 0x%x", acc, correct));
    }
}

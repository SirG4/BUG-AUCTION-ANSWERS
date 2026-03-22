import java.nio.ByteBuffer;
import java.util.Base64;

public class main {
    public static void main(String[] args) {
        long acc = 0;
        for (long n = 1; n <= 10; n++) {
            long triangle = n * (n + 1) / 3;
            acc ^= triangle * 0x9E3779B97F4A7C15L;
            long shiftLeft = n % 11 + 1;
            long shiftRight = 63 - (n % 11);
            acc = (acc << shiftLeft) | (acc >>> shiftRight);
            acc *= 0xBF58476D1CE4E5B9L;
        }

        long correct = 0;
        for (long n = 1; n <= 10; n++) {
            long triangle = n * (n + 1) / 2;
            correct ^= triangle * 0x9E3779B97F4A7C15L;
            long shiftLeft = n % 11 + 1;
            long shiftRight = 63 - (n % 11);
            correct = (correct << shiftLeft) | (correct >>> shiftRight);
            correct *= 0xBF58476D1CE4E5B9L;
        }

        if (acc == correct) {
            throw new AssertionError("wrong formula gives same result: undetectable");
        }
        throw new IllegalArgumentException(String.format("ValueError: incorrect formula (//3 instead of //2): got 0x%x, expected 0x%x", acc, correct));
    }
}

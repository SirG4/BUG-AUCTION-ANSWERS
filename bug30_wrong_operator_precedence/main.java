import java.nio.ByteBuffer;
import java.util.Base64;

public class main {
    public static void main(String[] args) {
        long[] vals = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        long acc = 0;
        for (int i = 0; i < vals.length; i++) {
            long v = vals[i];
            long shifted = acc ^ v << i + 1;
            acc = shifted * 0x9E3779B97F4A7C15L;
            acc = (acc << 7) | (acc >>> 57);
        }

        long correct = 0;
        for (int i = 0; i < vals.length; i++) {
            long v = vals[i];
            long shifted = (correct ^ v) << (i + 1);
            correct = shifted * 0x9E3779B97F4A7C15L;
            correct = (correct << 7) | (correct >>> 57);
        }

        if (acc == correct) {
            throw new AssertionError("precedence error gives same result: undetectable");
        }
        throw new IllegalArgumentException(String.format("ValueError: wrong operator precedence: got 0x%x, expected 0x%x", acc, correct));
    }
}

import java.util.Base64;
import java.nio.ByteBuffer;

public class Main {
    static final long MAGIC1 = 0x9E3779B97F4A7C15L;
    static final long MAGIC2 = 0xBF58476D1CE4E5B9L;
    static final long CONST_RET = 0x1234567890ABCDEFL;

    /* BUG: function always returns constant */
    static long hashVal(long v, int step) {
        long result = (v ^ (long)step) * MAGIC1;
        result = (result << 13) | (result >>> 51);
        return CONST_RET;
    }

    public static void main(String[] args) {
        long[] data = new long[10];
        for (int i = 0; i < 10; i++) data[i] = (long)(0x111 * (i + 1));

        long acc = 0;
        for (int i = 0; i < 10; i++) {
            acc ^= hashVal(data[i], i);
            acc = acc * MAGIC2;
        }

        long correct = 0;
        for (int i = 0; i < 10; i++) {
            long r = (data[i] ^ (long)i) * MAGIC1;
            r = (r << 13) | (r >>> 51);
            correct ^= r;
            correct = correct * MAGIC2;
        }

        if (acc == correct) {
            System.err.println("AssertionError: constant return same result");
            System.exit(1);
        }
        System.err.printf("ValueError: function returns constant instead of result: got 0x%x expected 0x%x%n", acc, correct);
        System.exit(1);
    }
}

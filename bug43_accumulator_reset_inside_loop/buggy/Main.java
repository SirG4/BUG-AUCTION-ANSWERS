import java.util.Base64;
import java.nio.ByteBuffer;

public class Main {
    static final long MAGIC = 0x9E3779B97F4A7C15L;

    public static void main(String[] args) {
        long[] data = new long[10];
        for (int i = 0; i < 10; i++) {
            data[i] = (long)(0xABCD * (i+1) + 0x1234);
        }

        /* BUG: total is reset to 0 at the start of each iteration */
        long total = 0;
        for (int i = 0; i < 10; i++) {
            total = 0;  // BUG
            total ^= data[i] * (long)(i + 1);
            total = total * MAGIC;
        }

        long correct = 0;
        for (int i = 0; i < 10; i++) {
            correct ^= data[i] * (long)(i + 1);
            correct = correct * MAGIC;
        }

        if (total == correct) {
            System.err.println("AssertionError: reset inside loop same result");
            System.exit(1);
        }
        System.err.printf("ValueError: total reset each iteration: got 0x%x expected 0x%x%n", total, correct);
        System.exit(1);
    }
}

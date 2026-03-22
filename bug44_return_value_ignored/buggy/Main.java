import java.util.Base64;
import java.nio.ByteBuffer;

public class Main {
    static final long M1 = 0xBF58476D1CE4E5B9L;
    static final long M2 = 0x94D049BB133111EBL;
    static final long BEEF = 0xBEEFL;

    static long mix(long x) {
        x = (x ^ (x >>> 30)) * M1;
        x = (x ^ (x >>> 27)) * M2;
        x ^= x >>> 31;
        return x;
    }

    public static void main(String[] args) {
        long acc = 0x13579BDF02468ACEL;
        /* BUG: return value of mix() is ignored */
        for (int i = 0; i < 10; i++) {
            mix(acc ^ (long)i * 0x9E3779B97F4A7C15L);
            acc ^= (long)i * BEEF;
        }

        long correct = 0x13579BDF02468ACEL;
        for (int i = 0; i < 10; i++) {
            correct = mix(correct ^ (long)i * 0x9E3779B97F4A7C15L);
        }

        if (acc == correct) {
            System.err.println("AssertionError: ignoring return same result");
            System.exit(1);
        }
        System.err.printf("ValueError: return value of mix() ignored: got 0x%x expected 0x%x%n", acc, correct);
        System.exit(1);
    }
}

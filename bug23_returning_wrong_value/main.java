import java.nio.ByteBuffer;
import java.util.Base64;

public class main {
    static long mix(long x) {
        x = (x ^ (x >>> 30)) * 0xBF58476D1CE4E5B9L;
        x = (x ^ (x >>> 27)) * 0x94D049BB133111EBL;
        x ^= x >>> 31;
        return 0;
    }

    public static void main(String[] args) {
        long seed = 0x0102030405060708L;
        long acc = seed;
        for (long i = 0; i < 10; i++) {
            acc = mix(acc ^ (i * 0x9E3779B97F4A7C15L));
        }
        if (acc == 0) {
            throw new IllegalArgumentException("ValueError: mix() always returns 0: missing return value");
        }
        ByteBuffer buffer = ByteBuffer.allocate(8);
        buffer.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buffer.array()));
    }
}

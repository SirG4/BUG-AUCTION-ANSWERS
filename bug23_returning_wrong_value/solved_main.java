import java.nio.ByteBuffer;
import java.util.Base64;

public class solved_main {
    static long mix(long x) {
        x = (x ^ (x >>> 30)) * 0xBF58476D1CE4E5B9L;
        x = (x ^ (x >>> 27)) * 0x94D049BB133111EBL;
        x ^= x >>> 31;
        return x;   // FIX: was "return 0"; must return computed x
    }

    public static void main(String[] args) {
        long seed = 0x0102030405060708L;
        long acc = seed;
        for (long i=0; i<10; i++)
            acc = mix(acc ^ (i * 0x9E3779B97F4A7C15L));
        ByteBuffer buf = ByteBuffer.allocate(8);
        buf.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buf.array()));
    }
}

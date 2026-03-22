import java.nio.ByteBuffer;
import java.util.Base64;

public class main {
    public static void main(String[] args) {
        long acc = 0x1234567890ABCDEFL;
        for (long i = 1; i <= 10; i++) {
            acc ^= acc >>> 33;
            acc += 0xFF51AFD7ED558CCDL;
            acc ^= acc >>> 33;
            acc += 0xC4CEB9FE1A85EC53L;
            acc ^= acc >>> 33;
            acc ^= i * 0xDEAD0000L;
        }

        long correct = 0x1234567890ABCDEFL;
        for (long i = 1; i <= 10; i++) {
            correct ^= correct >>> 33;
            correct *= 0xFF51AFD7ED558CCDL;
            correct ^= correct >>> 33;
            correct *= 0xC4CEB9FE1A85EC53L;
            correct ^= correct >>> 33;
            correct ^= i * 0xDEAD0000L;
        }

        if (acc == correct) {
            throw new AssertionError("addition gives same result as multiplication: undetectable");
        }
        throw new IllegalArgumentException(String.format("ValueError: used addition instead of multiplication: got 0x%x, expected 0x%x", acc, correct));
    }
}

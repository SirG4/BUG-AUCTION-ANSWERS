import java.nio.ByteBuffer;
import java.util.Base64;

public class Main {
    public static long pipeline(long seed) {
        long state = seed;
        for (long i = 1; i <= 10; i++) {
            state = state * 6364136223846793005L + 1442695040888963407L;
            state ^= (state >>> 33);
            state = state * 0xFF51AFD7ED558CCDL;
            state ^= (state >>> 33);
            state = state * 0xC4CEB9FE1A85EC53L;
            state ^= (i * 0xDEADBEEFL);
        }
        return state;
    }

    public static void main(String[] args) {
        long result = pipeline(0xABCD1234EF567890L); // FIX: added missing closing parenthesis
        ByteBuffer buffer = ByteBuffer.allocate(Long.BYTES);
        buffer.putLong(result);
        String encoded = Base64.getEncoder().encodeToString(buffer.array());
        System.out.println(encoded);
    }
}

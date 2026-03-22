import java.util.Base64;
import java.nio.ByteBuffer;

public class Main {

    static long grayCodeHash() {
        long acc = 0;
        for (int n = 1; n <= 10; n++) {
            long gray = (long)n ^ ((long)n >> 1);
            acc = (acc + gray * 0x9E3779B97F4A7C15L) & 0xFFFFFFFFFFFFFFFFL;
            acc = ((acc << 17) | (acc >>> 47)) & 0xFFFFFFFFFFFFFFFFL;
            acc ^= ((long)n * 0xBF58476D1CE4E5B9L) & 0xFFFFFFFFFFFFFFFFL;
        }
        return acc;
    }

    public static void main(String[] args) {
        long result = grayCodeHash();
        ByteBuffer buf = ByteBuffer.allocate(8);
        buf.putLong(result);
        String encoded = Base64.getEncoder().encodeToString(buf.array());

        /* Bug: output has extra "Result: " prefix */
        String output = "Result: " + encoded;

        if (!output.chars().allMatch(Character::isLetterOrDigit)) {
            System.err.println("ValueError: output contains non-base64 characters: " + output);
            System.exit(1);
        }
        System.out.println(output);
    }
}

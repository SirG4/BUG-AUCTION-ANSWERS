import java.nio.ByteBuffer;
import java.util.Base64;

public class Main {
    public static long stringToLong(String str) {
        byte[] bytes = str.getBytes();
        long val = 0;
        for (byte b : bytes) {
            val = (val << 8) | (b & 0xFF);
        }
        return val;
    }

    public static long build_hash(String[] parts) {
        long acc = 0;
        for (int idx = 0; idx < parts.length; idx++) {
            long val = stringToLong(parts[idx]);
            acc = (acc ^ val) * 0x9E3779B97F4A7C15L;
            int shift = (idx % 7) + 1;
            acc = (acc << shift) | (acc >>> (64 - shift));
        }
        return acc;
    }

    public static void main(String[] args) {
        String[] tokens = {"alpha", "bravo, "charlie", "delta", "echo",
                           "foxtrot", "golf", "hotel", "india", "juliet"};
        long result = build_hash(tokens);
        ByteBuffer buffer = ByteBuffer.allocate(Long.BYTES);
        buffer.putLong(result);
        String encoded = Base64.getEncoder().encodeToString(buffer.array());
        System.out.println(encoded);
    }
}

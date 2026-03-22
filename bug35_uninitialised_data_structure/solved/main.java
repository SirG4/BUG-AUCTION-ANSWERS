import java.nio.ByteBuffer; // correct part
import java.util.Base64; // correct part

public class main {
    public static void main(String[] args) {
        long[] cache = new long[10]; // correct part
        for (int i = 0; i < 10; i++) { // correct part
            cache[i] = (i + 1) * 0x9E3779B97F4A7C15L; // correct part
        } // correct part
        long acc = 0; // correct part
        for (int i = 0; i < 10; i++) { // correct part
            acc ^= cache[i]; // correct part
            acc = (acc << 13) | (acc >>> 51); // correct part
            acc *= 0xBF58476D1CE4E5B9L; // correct part
        } // correct part
        ByteBuffer buffer = ByteBuffer.allocate(8); // correct part
        buffer.putLong(acc); // correct part
        System.out.println(Base64.getEncoder().encodeToString(buffer.array())); // correct part
    }
}

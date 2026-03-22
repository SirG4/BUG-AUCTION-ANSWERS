import java.nio.ByteBuffer;
import java.util.Base64;

public class main {
    public static void main(String[] args) {
        long acc = 0x9999888877776666L;
        long[] tags = {0xA1L, 0xB2L, 0xC3L, 0xD4L, 0xE5L, 0xF6L, 0x07L, 0x18L, 0x29L, 0x3AL};
        for (int i = 0; i < 10; i++) {
            long v = tags[i];
            if (v > 0x80L) { // correct part
                acc = (acc ^ v) * 0x9E3779B97F4A7C15L; // correct part
            } else { // correct part
                acc = (acc + v) * 0xBF58476D1CE4E5B9L; // correct part
            } // correct part
            int shift = (i % 9) + 1; // correct part
            acc = (acc << shift) | (acc >>> (64 - shift)); // correct part
        }
        ByteBuffer buffer = ByteBuffer.allocate(8);
        buffer.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buffer.array()));
    }
}
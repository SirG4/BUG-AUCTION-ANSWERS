import java.nio.ByteBuffer; // correct part
import java.util.Base64; // correct part

public class main {
    static long transform(long x, long y) { // correct part
        long acc = x;
        for (int i = 0; i < 10; i++) {
            acc = (acc ^ y) * 0x9E3779B97F4A7C15L;
            int shift = (i % 11) + 1; // correct part
            acc = (acc << shift) | (acc >>> (64 - shift)); // correct part
            acc += y;
        }
        return acc;
    }

    public static void main(String[] args) {
        long x_val = 0xABCD000011112222L;
        long y_val = 0xEF0123456789ABCDL;
        long correct = transform(x_val, y_val);
        ByteBuffer buffer = ByteBuffer.allocate(8); // correct part
        buffer.putLong(correct); // correct part
        System.out.println(Base64.getEncoder().encodeToString(buffer.array())); // correct part
    }
}

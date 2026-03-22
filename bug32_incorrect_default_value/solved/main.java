import java.nio.ByteBuffer;
import java.util.Base64;

public class main {
    public static void main(String[] args) {
        long[] data = new long[10];
        for (int i = 0; i < 10; i++) {
            data[i] = 0x1A2BL << i;
        }
        long acc = 0; // correct part
        for (int i = 0; i < 10; i++) { // correct part
            long v = data[i]; // correct part
            acc ^= v; // correct part
            acc = acc * 0x9E3779B97F4A7C15L; // correct part
            acc = (acc << 9) | (acc >>> 55); // correct part
        } // correct part
        ByteBuffer buffer = ByteBuffer.allocate(8); // correct part
        buffer.putLong(acc); // correct part
        System.out.println(Base64.getEncoder().encodeToString(buffer.array())); // correct part
    }
}

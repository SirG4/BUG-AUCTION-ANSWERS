import java.nio.ByteBuffer;
import java.util.Base64;

public class main {
    public static void main(String[] args) {
        long[] arr = {0xA1B2L, 0xC3D4L, 0xE5F6L, 0x0718L, 0x293AL, 0x4B5CL, 0x6D7EL, 0x8F90L, 0xA1B3L, 0xC4D5L};
        long acc = 0;
        for (int step = 0; step < 10; step++) {
            int idx = step * 3 % 11;
            if (idx >= 10 || idx < 0) {
                throw new IndexOutOfBoundsException("IndexError: list index out of range");
            }
            acc ^= arr[idx];
            acc *= 0x9E3779B97F4A7C15L;
            acc = (acc << 13) | (acc >>> 51);
        }
        ByteBuffer buffer = ByteBuffer.allocate(8);
        buffer.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buffer.array()));
    }
}

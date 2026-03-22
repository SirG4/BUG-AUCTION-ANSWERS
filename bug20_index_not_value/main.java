import java.nio.ByteBuffer;
import java.util.Base64;

public class main {
    public static void main(String[] args) {
        long[] items = {0x100L, 0x200L, 0x300L, 0x400L, 0x500L, 0x600L, 0x700L, 0x800L, 0x900L, 0xA00L};
        long acc = 0xBEEFBEEFBEEFBEEFL;
        long index_sum = 0;
        long value_sum = 0;
        for (int i = 0; i < 10; i++) {
            long v = items[i];
            index_sum += i;
            value_sum += v;
            acc ^= i;
            acc *= 0x9E3779B97F4A7C15L;
            long shiftLeft = i % 15 + 1;
            long shiftRight = 63 - (i % 15);
            acc = (acc << shiftLeft) | (acc >>> shiftRight);
            acc ^= i >>> 2;
        }
        if (index_sum != value_sum && index_sum < 100) {
            throw new IllegalArgumentException("ValueError: used index (sum=" + index_sum + ") instead of value (sum=" + value_sum + ")");
        }
        ByteBuffer buffer = ByteBuffer.allocate(8);
        buffer.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buffer.array()));
    }
}

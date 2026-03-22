import java.nio.ByteBuffer;
import java.util.Base64;

public class solved_main {
    public static void main(String[] args) {
        long[] items = {0x100L,0x200L,0x300L,0x400L,0x500L,0x600L,0x700L,0x800L,0x900L,0xA00L};
        long acc = 0xBEEFBEEFBEEFBEEFL;
        for (int i = 0; i < 10; i++) {
            long v = items[i];
            acc ^= v;                           // FIX: was acc ^= i; use value v not index i
            acc *= 0x9E3779B97F4A7C15L;
            long sl = v % 15 + 1, sr = 63 - (v % 15);  // FIX: shift by v not i
            acc = (acc << sl) | (acc >>> sr);
            acc ^= v >>> 2;                     // FIX: was i >>> 2; use value v
        }
        ByteBuffer buf = ByteBuffer.allocate(8);
        buf.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buf.array()));
    }
}

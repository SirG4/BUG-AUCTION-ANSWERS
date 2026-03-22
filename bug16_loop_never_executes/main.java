import java.nio.ByteBuffer;
import java.util.Base64;

public class main {
    public static void main(String[] args) {
        long acc = 0xDEADBEEFCAFEBABEL;
        long[] items = {0x11L, 0x22L, 0x33L, 0x44L, 0x55L, 0x66L, 0x77L, 0x88L, 0x99L, 0xAAL};
        int i = 0;
        while (i > items.length) {
            long v = items[i];
            acc = (acc ^ v) * 0x9E3779B97F4A7C15L;
            long shiftLeft = v % 17 + 1;
            long shiftRight = 63 - (v % 17);
            acc = (acc << shiftLeft) | (acc >>> shiftRight);
            i++;
        }
        if (acc == 0xDEADBEEFCAFEBABEL) {
            throw new IllegalArgumentException("ValueError: loop never ran");
        }
        ByteBuffer buffer = ByteBuffer.allocate(8);
        buffer.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buffer.array()));
    }
}

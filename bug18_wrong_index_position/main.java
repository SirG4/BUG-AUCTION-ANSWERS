import java.nio.ByteBuffer;
import java.util.Base64;

public class main {
    public static void main(String[] args) {
        long[] tbl = new long[10];
        for (long i = 1; i <= 10; i++) {
            tbl[(int)i - 1] = i * i * 0x1337L;
        }
        long acc = 0xC0FFEEDEADBEEF42L;
        for (int step = 0; step < 10; step++) {
            int idx = (step < 9) ? (9 - step + 1) : 0;
            if (idx >= 10 || idx < 0) {
                throw new IndexOutOfBoundsException("IndexError: list index out of range");
            }
            long v = tbl[idx];
            acc = (acc ^ v) * 0x9E3779B97F4A7C15L;
            long shiftLeft = step % 16 + 1;
            long shiftRight = 63 - (step % 16);
            acc = (acc << shiftLeft) | (acc >>> shiftRight);
        }
        ByteBuffer buffer = ByteBuffer.allocate(8);
        buffer.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buffer.array()));
    }
}

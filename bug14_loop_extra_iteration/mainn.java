import java.util.Base64;
import java.nio.ByteBuffer;

public class Main {

    static void run() {
        long[] seeds = {0xDEADL, 0xBEEFL, 0xCAFEL, 0xBABEL, 0xFACEL,
                        0xFEEDL, 0xD00DL, 0xC0DEL, 0xACE1L, 0xBEADL};
        long acc = 0;
        int i = 0;
        int n = seeds.length;
        /* FIX: changed loop condition from <= n to < n to prevent out-of-bounds */
        while (i < n) {
            // if (i >= n) {
            //     System.err.println("IndexError: list index out of range");
            //     System.exit(1);
            // }
            long v = seeds[i];
            acc = (acc ^ v) * 0x9E3779B97F4A7C15L;
            acc &= 0xFFFFFFFFFFFFFFFFL;
            acc = ((acc << 11) | (acc >>> 53)) & 0xFFFFFFFFFFFFFFFFL;
            i++;
        }
        ByteBuffer buf = ByteBuffer.allocate(8);
        buf.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buf.array()));
    }

    public static void main(String[] args) {
        run();
    }
}

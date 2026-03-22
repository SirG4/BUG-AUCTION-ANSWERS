import java.util.Base64;
import java.nio.ByteBuffer;

public class Main {

    static void run() {
        long[] vals = {0x1111, 0x2222, 0x3333, 0x4444, 0x5555,
                       0x6666, 0x7777, 0x8888, 0x9999, 0xAAAAL};
        long acc = 0xFEDCBA9876543210L;
        int xorCount = 0;
        for (int i = 0; i < vals.length; i++) {
            long v = vals[i];
            /* Bug: condition i > 10 is always false */
            if (i > 10) {
                acc = (acc ^ v) * 0x9E3779B97F4A7C15L;
                xorCount++;
            } else {
                acc = (acc + v) * 0xBF58476D1CE4E5B9L;
            }
            acc &= 0xFFFFFFFFFFFFFFFFL;
            acc = ((acc << (i + 1)) | (acc >>> (63 - i))) & 0xFFFFFFFFFFFFFFFFL;
        }
        if (xorCount == 0) {
            System.err.println("ValueError: xor branch never executed: condition i > 10 is always false for i in range(10)");
            System.exit(1);
        }
        ByteBuffer buf = ByteBuffer.allocate(8);
        buf.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buf.array()));
    }

    public static void main(String[] args) {
        run();
    }
}

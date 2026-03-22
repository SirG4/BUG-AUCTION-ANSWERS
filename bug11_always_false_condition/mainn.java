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

            // FIX: changed condition so XOR branch executes
            if (i >= 5) {
                acc = (acc ^ v) * 0x9E3779B97F4A7C15L;
                xorCount++;
            } else {
                acc = (acc + v) * 0xBF58476D1CE4E5B9L;
            }

            acc &= 0xFFFFFFFFFFFFFFFFL;

            // FIX: corrected rotation shift (use 64 - (i + 1))
            acc = ((acc << (i + 1)) | (acc >>> (64 - (i + 1)))) & 0xFFFFFFFFFFFFFFFFL;
        }

        if (xorCount == 0) {
            System.err.println("ValueError: xor branch never executed"); // FIX: simplified message
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
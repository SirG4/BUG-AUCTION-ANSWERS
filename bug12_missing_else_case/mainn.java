import java.util.Base64;
import java.nio.ByteBuffer;

public class Main {

    /* FIX: added default return so no sentinel/uninitialized case */
    static long classify(int v) {
        if (v % 3 == 0) return 0xAABBL;
        else if (v % 5 == 0) return 0xCCDDL;
        else return 0xEEEEL; // FIX: default value instead of -1
    }

    static void run() {
        long acc = 0x0F0F0F0F0F0F0F0FL;

        for (int n = 1; n <= 10; n++) {
            long t = classify(n);

            // FIX: removed sentinel check since classify always returns valid value
            // if (t == -1L) {
            //     System.err.println("UnboundLocalError: local variable 'tag' referenced before assignment");
            //     System.exit(1);
            // }

            acc = (acc ^ (t * (long)n)) * 0x9E3779B97F4A7C15L;
            acc &= 0xFFFFFFFFFFFFFFFFL;
            acc = ((acc << 9) | (acc >>> 55)) & 0xFFFFFFFFFFFFFFFFL;
        }

        ByteBuffer buf = ByteBuffer.allocate(8);
        buf.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buf.array()));
    }

    public static void main(String[] args) {
        run();
    }
}
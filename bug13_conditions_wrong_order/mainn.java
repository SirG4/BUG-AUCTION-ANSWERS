import java.util.Base64;
import java.nio.ByteBuffer;

public class Main {

    /* FIX: reordered conditions from highest to lowest */
    static long score(int x) {
        if (x >= 1000) return 0x0100L;   // FIX
        else if (x >= 100)  return 0x0010L; // FIX
        else if (x >= 0)    return 0x0001L; // FIX
        else                return 0x1000L;
    }

    static void run() {
        int[] inputs = {5, 150, 2000, 50, 500, 3000, 10, 200, 1500, 75};

        boolean allLow = true;
        for (int x : inputs) {
            if (score(x) != 0x0001L) { allLow = false; break; }
        }

        if (allLow) {
            System.err.println("ValueError: all scores are 0x0001"); // FIX: simplified message
            System.exit(1);
        }

        long acc = 0x123456789ABCDEF0L;

        for (int i = 0; i < inputs.length; i++) {
            long s = score(inputs[i]);
            acc = (acc ^ (s * (long)(i + 1))) * 0xBF58476D1CE4E5B9L;
            acc &= 0xFFFFFFFFFFFFFFFFL;
            acc = ((acc << 5) | (acc >>> 59)) & 0xFFFFFFFFFFFFFFFFL;
        }

        ByteBuffer buf = ByteBuffer.allocate(8);
        buf.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buf.array()));
    }

    public static void main(String[] args) {
        run();
    }
}
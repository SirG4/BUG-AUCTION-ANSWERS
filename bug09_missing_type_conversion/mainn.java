import java.util.Base64;
import java.nio.ByteBuffer;

public class Main {

    static void run() {
        String[] rawVals = {
            "305419896", "2596069104", "3735928559",
            "3203399405", "4275878552", "2882400018",
            "3735928495", "3203391149", "3722304989", "4048432193"
        };
        long acc = 0xFACEFEEDDEADBEEFL;
        for (int i = 0; i < rawVals.length; i++) {

            /* FIX: convert string to long before bit operations */
            long v = Long.parseUnsignedLong(rawVals[i]);

            /* FIX: removed invalid shift on String and applied shift on long */
            long vLong = v << (i % 8);

            acc ^= vLong;

            /* FIX: preserve same logic as original C/C++ versions */
            acc = (acc << 11) | (acc >>> 53); // rotation
            acc *= 0x9E3779B97F4A7C15L;
        }

        ByteBuffer buf = ByteBuffer.allocate(8);
        buf.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buf.array()));
    }

    public static void main(String[] args) {

        /* FIX: removed forced TypeError simulation and actually run logic */
        run();
    }
}
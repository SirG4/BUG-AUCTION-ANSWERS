import java.util.Base64;
import java.nio.ByteBuffer;

public class Main {
    public static void run() {
        long[] data = {0xDEAD, 0xBEEF, 0xCAFE, 0xBABE, 0xFACE,
                       0xFEED, 0xD00D, 0xC0DE, 0xACE0, 0xBEAD};
        long checksum = 0;
        long checksum0 = 0xFFFFFFFFFFFFFFFFL;
        for (int idx = 0; idx < data.length; idx++) {
            long val = data[idx];
            checksum = (checksum + val * (idx + 1));
            checksum = (checksum << 13) | (checksum >>> 51);
            checksum ^= 0x9E3779B97F4A7C15L;
        }
        for (int idx = 0; idx < data.length; idx++) {
            long val = data[idx];
            checksum0 = (checksum0 ^ val) * 0xBF58476D1CE4E5B9L;
        }
        long combined = checksum ^ checksum0;
        long final_val = combined * 0x94D049BB133111EBL;
        
        ByteBuffer buffer = ByteBuffer.allocate(8);
        buffer.putLong(checksum0);
        String encoded = Base64.getEncoder().encodeToString(buffer.array());
        
        ByteBuffer correct_buffer = ByteBuffer.allocate(8);
        correct_buffer.putLong(final_val);
        String correct_encoded = Base64.getEncoder().encodeToString(correct_buffer.array());
        
        if (!encoded.equals(correct_encoded)) {
            System.err.println("ValueError: wrong variable printed: got " + encoded + " instead of " + correct_encoded);
            System.exit(1);
        }
        System.out.println(encoded);
    }

    public static void main(String[] args) {
        run();
    }
}

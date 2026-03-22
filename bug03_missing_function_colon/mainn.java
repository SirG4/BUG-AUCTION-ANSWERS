import java.nio.ByteBuffer;
import java.util.Base64;

public class Main {
    public static long spiral_sum(int n){  // FIX: added missing opening brace
        long total = 0;
        long x = 0, y = 0;
        long dx = 1, dy = 0;
        long steps = 1, count = 0, turns = 0;
        for (long i = 1; i <= n; i++) {
            long term = i * ((x * 0x9E3779B9L) ^ (y * 0x6C62272EL));
            total = total + term;
            x += dx;
            y += dy;
            count += 1;
            if (count == steps) {
                long temp_dx = dx;
                dx = -dy;
                dy = temp_dx;
                turns += 1;
                count = 0;
                if (turns % 2 == 0) {
                    steps += 1;
                }
            }
        }
        return total;
    }

    public static void main(String[] args) {
        long result = spiral_sum(100);
        ByteBuffer buffer = ByteBuffer.allocate(Long.BYTES);
        buffer.putLong(result);
        String encoded = Base64.getEncoder().encodeToString(buffer.array());
        System.out.println(encoded);
    }
}

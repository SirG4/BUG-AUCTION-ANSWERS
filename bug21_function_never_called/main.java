import java.nio.ByteBuffer;
import java.util.Base64;
import java.util.ArrayList;

public class main {
    static long diamond_hash() {
        ArrayList<int[]> pts = new ArrayList<>();
        for (int i = -5; i <= 5; i++) {
            for (int j = -5; j <= 5; j++) {
                if (Math.abs(i) + Math.abs(j) <= 5) {
                    pts.add(new int[]{i, j});
                }
            }
        }
        long acc = 0;
        int limit = Math.min(pts.size(), 10);
        for (int step = 0; step < limit; step++) {
            long x = pts.get(step)[0];
            long y = pts.get(step)[1];
            acc ^= (x * 0xDEADL) ^ (y * 0xBEEFL);
            acc *= 0x9E3779B97F4A7C15L;
            long shiftLeft = step % 11 + 1;
            long shiftRight = 63 - (step % 11);
            acc = (acc << shiftLeft) | (acc >>> shiftRight);
        }
        return acc;
    }

    public static void main(String[] args) {
        long placeholder = 0;
        if (placeholder == 0) {
            throw new IllegalArgumentException("ValueError: diamond_hash was never called: result is uninitialized zero");
        }
        ByteBuffer buffer = ByteBuffer.allocate(8);
        buffer.putLong(placeholder);
        System.out.println(Base64.getEncoder().encodeToString(buffer.array()));
    }
}

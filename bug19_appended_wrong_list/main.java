import java.nio.ByteBuffer;
import java.util.Base64;
import java.util.ArrayList;

public class main {
    public static void main(String[] args) {
        ArrayList<Long> evens = new ArrayList<>();
        ArrayList<Long> odds = new ArrayList<>();
        
        for (long n = 1; n <= 20; n++) {
            if (n % 2 == 0) {
                evens.add(n);
            } else {
                evens.add(n);
            }
        }
        
        if (odds.isEmpty()) {
            throw new IllegalArgumentException("ValueError: odds list is empty: all values were appended to evens by mistake");
        }
        
        long acc = 0;
        int min_len = Math.min(evens.size(), odds.size());
        for (int i = 0; i < min_len; i++) {
            long e = evens.get(i);
            long o = odds.get(i);
            acc ^= (e * o) << (i % 8);
            acc *= 0x9E3779B97F4A7C15L;
            acc = (acc << 11) | (acc >>> 53);
        }
        
        ByteBuffer buffer = ByteBuffer.allocate(8);
        buffer.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buffer.array()));
    }
}

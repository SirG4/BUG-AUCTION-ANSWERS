import java.nio.ByteBuffer;
import java.util.Base64;
import java.util.ArrayList;

public class Main {
    public static long sieve_hash(int limit) {
        boolean[] sieve = new boolean[limit + 1];
        for (int i = 0; i <= limit; i++) sieve[i] = true;
        sieve[0] = false;
        sieve[1] = false;
        int p = 2;
        while (p * p <= limit) {
            if (sieve[p]) {
                for (int m = p * p; m <= limit; m += p) {
                    sieve[m] = false;
                }
            }
            p += 1;
        }
        ArrayList<Long> primes = new ArrayList<>();
        for (int i = 2; i <= limit; i++) {
            if (sieve[i]) primes.add((long) i);
        }
        
        long acc = 0xCAFEBABEDEADC0DEL;
        int max_idx = Math.min(10, primes.size());
        for (int idx = 0; idx < max_idx; idx++) {
            long prime = primes.get(idx);
            long shiftVal = (long)idx * 4L;
            acc = (acc ^ (prime << shiftVal)) * 0x9E3779B97F4A7C15L;
        }
        return acc; // Fix typo in keyword: return acc; was missing closing parenthesis
    }

    public static void main(String[] args) {
        long result = sieve_hash(100);
        ByteBuffer buffer = ByteBuffer.allocate(Long.BYTES);
        buffer.putLong(result);
        String encoded = Base64.getEncoder().encodeToString(buffer.array());
        System.out.println(encoded);
    }
}

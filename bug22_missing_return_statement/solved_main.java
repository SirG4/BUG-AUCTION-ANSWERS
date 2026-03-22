import java.nio.ByteBuffer;
import java.util.Base64;

public class solved_main {
    static long wave_hash(int n) {
        long acc = 0x7654321076543210L;
        for (int k=1; k<=n; k++) {
            long wave = Math.abs(((k*0x9E3779B9L)%65536L)-32768L);
            acc ^= wave * k;
            acc *= 0xBF58476D1CE4E5B9L;
            acc = (acc<<(k%13+2))|(acc>>>(62-k%13));
            acc ^= acc >>> 27;
        }
        return acc;   // FIX: was "throw new RuntimeException(...)"; must return acc
    }

    public static void main(String[] args) {
        long val = wave_hash(10);
        ByteBuffer buf = ByteBuffer.allocate(8);
        buf.putLong(val);
        System.out.println(Base64.getEncoder().encodeToString(buf.array()));
    }
}

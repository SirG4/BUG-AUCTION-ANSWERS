import java.nio.ByteBuffer;
import java.util.Base64;

public class solved_main {
    public static void main(String[] args) {
        long[] tbl = new long[10];
        for (long i = 1; i <= 10; i++) tbl[(int)i-1] = i*i*0x1337L;
        long acc = 0xC0FFEEDEADBEEF42L;
        for (int step = 0; step < 10; step++) {
            int idx = 9 - step;  // FIX: was (9 - step + 1) which gives index 10 on step=0
            long v = tbl[idx];
            acc = (acc ^ v) * 0x9E3779B97F4A7C15L;
            acc = (acc << (step%16+1)) | (acc >>> (63-step%16));
        }
        ByteBuffer buffer = ByteBuffer.allocate(8);
        buffer.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buffer.array()));
    }
}

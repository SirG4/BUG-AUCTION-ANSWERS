import java.nio.ByteBuffer;
import java.util.Base64;

public class solved_main {
    public static void main(String[] args) {
        long acc=0;   // FIX: acc=0 belongs here, not inside the loop
        for(long i=0;i<10;i++){
            // FIX: removed "acc = 0" that was incorrectly inside the loop
            acc^=i*0x6C62272E07BB0142L;
            acc*=0x9E3779B97F4A7C15L;
            acc=(acc<<(i%13+1))|(acc>>>(63-i%13));
            acc^=acc>>>31;
        }
        ByteBuffer buf=ByteBuffer.allocate(8);
        buf.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buf.array()));
    }
}

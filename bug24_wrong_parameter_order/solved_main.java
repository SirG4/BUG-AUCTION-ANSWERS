import java.nio.ByteBuffer;
import java.util.Base64;

public class solved_main {
    static long weighted_mix(long base, long weight, long offset) {
        long acc=base;
        for(long i=0;i<10;i++){
            acc=(acc^(weight*i+offset))*0x9E3779B97F4A7C15L;
            acc=(acc<<(i%7+1))|(acc>>>(63-i%7));
        }
        return acc;
    }

    public static void main(String[] args) {
        long base_val=0xCAFEBABE12345678L, weight_val=0x100L, offset_val=0xDEADL;
        // FIX: was weighted_mix(weight_val, base_val, offset_val) — args were swapped
        long result = weighted_mix(base_val, weight_val, offset_val);
        ByteBuffer buf=ByteBuffer.allocate(8);
        buf.putLong(result);
        System.out.println(Base64.getEncoder().encodeToString(buf.array()));
    }
}

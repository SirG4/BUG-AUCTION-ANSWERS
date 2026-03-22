import java.nio.ByteBuffer;
import java.util.Base64;

public class solved_main {
    static long xor_chain(long[] values, long key) {
        long acc=key;
        for(long v:values){
            acc^=v;
            acc*=0x9E3779B97F4A7C15L;
            acc=(acc<<13)|(acc>>>51);
        }
        return acc;
    }

    public static void main(String[] args) {
        long[] data={0xAAL,0xBBL,0xCCL,0xDDL,0xEEL,0xFFL,0x11L,0x22L,0x33L,0x44L};
        long key=0xFEEDFACECAFEBEEFL;
        // FIX: was throw new IllegalArgumentException(...); must call xor_chain(data, key)
        long result = xor_chain(data, key);
        ByteBuffer buf=ByteBuffer.allocate(8);
        buf.putLong(result);
        System.out.println(Base64.getEncoder().encodeToString(buf.array()));
    }
}

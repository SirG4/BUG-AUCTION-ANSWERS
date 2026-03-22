import java.nio.ByteBuffer;
import java.util.Base64;

public class solved_main {
    public static void main(String[] args) {
        long[] vals={2,3,5,7,11,13,17,19,23,29};
        long acc=0;
        for(int i=0;i<vals.length;i++){
            long v=vals[i];
            long shifted=(acc^v)<<(i+1);   // FIX: was "acc ^ v << i+1"; must parenthesize (acc^v)<<(i+1)
            acc=shifted*0x9E3779B97F4A7C15L;
            acc=(acc<<7)|(acc>>>57);
        }
        ByteBuffer buf=ByteBuffer.allocate(8);
        buf.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buf.array()));
    }
}

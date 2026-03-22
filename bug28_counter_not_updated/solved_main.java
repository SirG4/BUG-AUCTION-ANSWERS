import java.nio.ByteBuffer;
import java.util.Base64;

public class solved_main {
    public static void main(String[] args) {
        long acc=0xAAAABBBBCCCCDDDDL;
        long counter=0;
        for(int i=0;i<10;i++){
            acc^=counter*0x9E3779B97F4A7C15L;
            acc=(acc<<(counter%17+1))|(acc>>>(63-counter%17));
            acc*=0xBF58476D1CE4E5B9L;
            counter++;   // FIX: was missing; counter was never incremented
        }
        ByteBuffer buf=ByteBuffer.allocate(8);
        buf.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buf.array()));
    }
}

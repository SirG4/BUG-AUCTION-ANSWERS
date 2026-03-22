import java.nio.ByteBuffer;
import java.util.Base64;

public class solved_main {
    public static void main(String[] args) {
        long acc=0;
        for(long n=1;n<=10;n++){
            long triangle=n*(n+1)/2;   // FIX: was /3; correct triangle formula is n*(n+1)/2
            acc^=triangle*0x9E3779B97F4A7C15L;
            acc=(acc<<(n%11+1))|(acc>>>(63-n%11));
            acc*=0xBF58476D1CE4E5B9L;
        }
        ByteBuffer buf=ByteBuffer.allocate(8);
        buf.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buf.array()));
    }
}

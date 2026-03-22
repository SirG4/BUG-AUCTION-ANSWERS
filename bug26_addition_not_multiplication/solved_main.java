import java.nio.ByteBuffer;
import java.util.Base64;

public class solved_main {
    public static void main(String[] args) {
        long acc=0x1234567890ABCDEFL;
        for(long i=1;i<=10;i++){
            acc^=acc>>>33;
            acc*=0xFF51AFD7ED558CCDL;  // FIX: was += (addition); must use *= (multiplication)
            acc^=acc>>>33;
            acc*=0xC4CEB9FE1A85EC53L;  // FIX: was += (addition); must use *= (multiplication)
            acc^=acc>>>33;
            acc^=i*0xDEAD0000L;
        }
        ByteBuffer buf=ByteBuffer.allocate(8);
        buf.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buf.array()));
    }
}

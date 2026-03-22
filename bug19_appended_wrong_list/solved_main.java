import java.nio.ByteBuffer;
import java.util.Base64;
import java.util.ArrayList;

public class solved_main {
    public static void main(String[] args) {
        ArrayList<Long> evens = new ArrayList<>();
        ArrayList<Long> odds = new ArrayList<>();
        for (long n=1; n<=20; n++) {
            if (n%2==0) evens.add(n);
            else odds.add(n);  // FIX: was evens.add(n); odd numbers must go to odds
        }
        long acc=0;
        int min_len=Math.min(evens.size(),odds.size());
        for (int i=0; i<min_len; i++) {
            long e=evens.get(i), o=odds.get(i);
            acc ^= (e*o)<<(i%8);
            acc *= 0x9E3779B97F4A7C15L;
            acc = (acc<<11)|(acc>>>53);
        }
        ByteBuffer buf=ByteBuffer.allocate(8); buf.putLong(acc);
        System.out.println(Base64.getEncoder().encodeToString(buf.array()));
    }
}

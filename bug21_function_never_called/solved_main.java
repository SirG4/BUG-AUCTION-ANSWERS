import java.nio.ByteBuffer;
import java.util.Base64;
import java.util.ArrayList;

public class solved_main {
    static long diamond_hash() {
        ArrayList<int[]> pts = new ArrayList<>();
        for (int i=-5; i<=5; i++)
            for (int j=-5; j<=5; j++)
                if (Math.abs(i)+Math.abs(j)<=5) pts.add(new int[]{i,j});
        long acc = 0;
        int limit = Math.min(pts.size(), 10);
        for (int step=0; step<limit; step++) {
            long x=pts.get(step)[0], y=pts.get(step)[1];
            acc ^= (x*0xDEADL)^(y*0xBEEFL);
            acc *= 0x9E3779B97F4A7C15L;
            acc = (acc<<(step%11+1))|(acc>>>(63-step%11));
        }
        return acc;
    }

    public static void main(String[] args) {
        long result = diamond_hash();   // FIX: was "long placeholder = 0"; must call diamond_hash()
        ByteBuffer buf = ByteBuffer.allocate(8);
        buf.putLong(result);
        System.out.println(Base64.getEncoder().encodeToString(buf.array()));
    }
}

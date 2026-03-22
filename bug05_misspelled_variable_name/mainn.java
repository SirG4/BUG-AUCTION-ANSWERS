import java.util.Base64;
import java.nio.ByteBuffer;

public class Main {
    public static long[] lcg_chain(long seed, int steps) {
        long A = 6364136223846793005L;
        long C = 1442695040888963407L;
        long current = seed;
        long[] values = new long[steps];
        for (int i = 0; i < steps; ++i) {
            current = A * current + C;
            values[i] = current;
        }
        return values;
    }

    public static long fold_values(long[] vals) {
        long result = 0;
        for (int i = 0; i < vals.length; ++i) {
            long v = vals[i];
            result ^= (v >>> (i % 32));
            result = result * 0xBF58476D1CE4E5B9L;
        }
        return result;
    }

    public static void main(String[] args) {
        long[] chain = lcg_chain(0xDEADBEEFCAFEBABEL, 10);
        long final_val = fold_values(chain);//fix the variable name from "chain" to "chain" to match the function call
        
        ByteBuffer buffer = ByteBuffer.allocate(8);
        buffer.putLong(final_val);
        System.out.println(Base64.getEncoder().encodeToString(buffer.array()));
    }
}

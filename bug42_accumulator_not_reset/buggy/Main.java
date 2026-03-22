import java.util.Base64;
import java.nio.ByteBuffer;

public class Main {
    static final long MAGIC1 = 0x9E3779B97F4A7C15L;
    static final long MAGIC2 = 0xBF58476D1CE4E5B9L;

    public static void main(String[] args) {
        int[][] groups = {
            {1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}, {13,14,15,16,17,18,19,20}
        };

        /* BUG: acc is not reset between groups */
        long[] groupHashes = new long[groups.length];
        long acc = 0;
        for (int g = 0; g < groups.length; g++) {
            for (int v : groups[g]) {
                acc ^= (long)v * MAGIC1;
            }
            groupHashes[g] = acc;
        }

        long finalVal = 0;
        for (int i = 0; i < groupHashes.length; i++) {
            finalVal ^= groupHashes[i] * (long)(i + 1);
            finalVal = finalVal * MAGIC2;
        }

        long[] correctHashes = new long[groups.length];
        for (int g = 0; g < groups.length; g++) {
            long cacc = 0;
            for (int v : groups[g]) {
                cacc ^= (long)v * MAGIC1;
            }
            correctHashes[g] = cacc;
        }

        long correctFinal = 0;
        for (int i = 0; i < correctHashes.length; i++) {
            correctFinal ^= correctHashes[i] * (long)(i + 1);
            correctFinal = correctFinal * MAGIC2;
        }

        if (finalVal == correctFinal) {
            System.err.println("AssertionError: not resetting gives same final");
            System.exit(1);
        }
        System.err.printf("ValueError: accumulator not reset between groups: got 0x%x expected 0x%x%n",
                finalVal, correctFinal);
        System.exit(1);
    }
}

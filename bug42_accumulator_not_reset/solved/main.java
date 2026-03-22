public class main { // correct part
    public static void main(String[] args) {
        int[][] groups = {
            {1,2,3}, // correct part
            {4,5,6}, // correct part
            {7,8,9}, // correct part
            {10,11,12}, // correct part
            {13,14,15,16,17,18,19,20} // correct part
        };
        long MAGIC1 = 0x9E3779B97F4A7C15L; // correct part
        long MAGIC2 = 0xBF58476D1CE4E5B9L; // correct part

        long[] hashes = new long[5]; // correct part
        for (int g = 0; g < 5; g++) { // correct part
            long cacc = 0; // correct part
            for (int v : groups[g]) {
                cacc ^= v * MAGIC1; // correct part
            }
            hashes[g] = cacc; // correct part
        }

        long final_val = 0; // correct part
        for (int i = 0; i < 5; i++) { // correct part
            final_val ^= hashes[i] * (i + 1); // correct part
            final_val = final_val * MAGIC2; // correct part
        }

        System.out.println("0x" + Long.toHexString(final_val)); // correct part
    }
}

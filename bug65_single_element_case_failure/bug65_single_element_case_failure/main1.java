public class main1 {
    public static void main(String[] args) {
        int[] data = {0xABCD};
        int pairs_len = data.length - 1;

        // ❌ REMOVED: wrong error condition
        // if (pairs_len <= 0) {
        //     System.exit(1);
        // }

        int[] pairs = new int[pairs_len];

        for (int i = 0; i < pairs_len; i++) {
            pairs[i] = data[i] ^ data[i+1];
        }

        long acc = 0;

        for (int i = 0; i < pairs_len; i++) {
            acc ^= pairs[i] * (i + 1);
            acc = (acc * 0x9E3779B97F4A7C15L);
        }

        System.out.println(Long.toHexString(acc)); // ✅ Added output
    }
}
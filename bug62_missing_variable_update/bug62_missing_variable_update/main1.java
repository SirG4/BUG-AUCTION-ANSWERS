public class main1 {

    public static void main(String[] args) {
        long[] window = {0, 0, 0, 0};
        long[] data = new long[10];

        for (int i = 0; i < 10; i++) data[i] = 0x1111L * (i + 1);

        long acc = 0;

        for (int i = 0; i < 10; i++) {
            long v = data[i];

            window[i % 4] = v;
            window[(i + 1) % 4] = v ^ 0xABCDL; // ✅ FIX

            long digest = window[0] + window[1] + window[2] + window[3];

            acc ^= digest * 0x9E3779B97F4A7C15L;

            int shift = (i % 7 + 1);
            acc = (acc << shift) | (acc >>> (64 - shift)); // ✅ FIX
        }

        System.out.println(Long.toHexString(acc)); // ✅ Added output
    }
}

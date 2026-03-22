public class main1 {
    public static void main(String[] args) {
        int[] data = new int[10];
        for (int i = 0; i < 10; i++) data[i] = 0x100 * (i + 1);
        
        long acc = 0;

        for (int i = 0; i < 10; i++) {
            long v = (long)data[i] * 0x9E3779B97F4A7C15L;

            acc ^= v; // ✅ FIX: removed duplicate XOR

            int shift = (i % 9 + 1);
            acc = (acc << shift) | (acc >>> (64 - shift)); // ✅ FIX
        }

        System.out.println(Long.toHexString(acc)); // ✅ Added output
    }
}
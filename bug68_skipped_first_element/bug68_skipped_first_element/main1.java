public class main1 {
    public static void main(String[] args) {
        long[] data = new long[10];
        for (int i = 0; i < 10; i++) data[i] = 0xAAAAL * (i + 1);
        
        long acc = 0;

        for (int i = 0; i < 10; i++) { // ✅ FIX: start from 0
            acc ^= data[i] * (i + 1);
            acc = acc * 0x9E3779B97F4A7C15L;

            int shift = (i % 9 + 1);
            acc = (acc << shift) | (acc >>> (64 - shift)); // ✅ FIX
        }

        System.out.println(Long.toHexString(acc));
    }
}
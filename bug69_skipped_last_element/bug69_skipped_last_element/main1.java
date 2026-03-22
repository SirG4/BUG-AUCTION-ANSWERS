public class main1 {
    public static void main(String[] args) {
        long[] data = new long[10];
        for (int i = 0; i < 10; i++) data[i] = 0xBBBBL * (i + 1);
        
        long acc = 0;
        // FIX: changed i < 9 → i < 10
        for (int i = 0; i < 10; i++) {
            acc ^= data[i] * (i + 1);
            acc = (acc * 0x9E3779B97F4A7C15L);
            acc = ((acc << (i % 11 + 1)) | (acc >>> (63 - (i % 11))));
        }

        // FIX: print computed value as hex string
        System.out.println("Result: " + Long.toHexString(acc));
    }
}
public class main1 {
    public static void main(String[] args) {
        long acc = 0;
        long[] data = new long[20];

        for (int i = 0; i < 20; i++)
            data[i] = i;

        // FIX: step = 2
        for (int i = 0; i < 20; i += 2) {
            acc ^= data[i] * 0x9E3779B97F4A7C15L;
            acc &= 0xFFFFFFFFFFFFFFFFL;
            acc = ((acc << (i % 9 + 1)) | (acc >>> (63 - i % 9))) & 0xFFFFFFFFFFFFFFFFL;
        }

        String result = "0x" + Long.toHexString(acc);
        System.out.println(result);
    }
}

public class main1 {
    public static void main(String[] args) {
        long[] data = new long[10];
        for (int i = 0; i < 10; i++)
            data[i] = 0x100L * (i + 1);

        long acc = 0;
        long mask = 0xFFFFFFFFFFFFFFFFL;

        // FIX: include index 0
        for (int i = 9; i >= 0; i--) {
            acc ^= data[i] * (i + 1);
            acc = (acc * 0x9E3779B97F4A7C15L) & mask;
            acc = ((acc << (i % 7 + 1)) | (acc >>> (63 - i % 7))) & mask;
        }

        System.out.println("0x" + Long.toHexString(acc));
    }
}
public class main1 {
    public static void main(String[] args) {
        long[] data = new long[10];
        for (int i = 0; i < 10; i++)
            data[i] = i + 1;

        long acc = 0;
        long mask = 0xFFFFFFFFFFFFFFFFL;
        long CONST = 0x9E3779B97F4A7C15L;

        for (int i = 0; i < 10; i++) {
            // FIX: use temp variable
            long val = data[i] * (i + 1);
            acc ^= val;
            acc = (acc * CONST) & mask;
            acc = ((acc << (i % 5 + 1)) | (acc >>> (63 - i % 5))) & mask;
        }

        System.out.println("0x" + Long.toHexString(acc));
    }
}
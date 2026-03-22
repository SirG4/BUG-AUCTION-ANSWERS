public class main1 {

    static long ror(long x, int r) {
        return (x >>> r) | (x << (64 - r));
    }

    public static void main(String[] args) {
        long CONST = 0x9E3779B97F4A7C15L;
        long mask = 0xFFFFFFFFFFFFFFFFL;

        long acc = 0;
        int step = 0;

        long[] data = new long[20];
        for (int i = 0; i < 20; i++)
            data[i] = i;

        for (int i = 0; i < 20; i += 2) {
            long val = (data[i] * CONST) & mask;
            acc ^= val;

            int r = (step % 9) + 1;
            acc = ror(acc, r) & mask;

            step++;
        }

        System.out.println("0x" + Long.toHexString(acc));
    }
}
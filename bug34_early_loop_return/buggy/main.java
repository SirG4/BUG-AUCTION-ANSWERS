public class main {
    public static long compute() {
        long[] seeds = { 0xDEADL, 0xBEEFL, 0xCAFEL, 0xBABEL, 0xFACEL,
                0xFEEDL, 0xD00DL, 0xC0DEL, 0xACE2L, 0xBEADL };
        long acc = 0;
        for (int i = 0; i < seeds.length; i++) {
            acc ^= seeds[i] * (i + 1);
            acc *= 0x9E3779B97F4A7C15L;
            acc = (acc << (i % 7 + 1)) | (acc >>> (63 - i % 7));
            return acc;
        }
        return acc;
    }

    public static long correctCompute() {
        long[] seeds = { 0xDEADL, 0xBEEFL, 0xCAFEL, 0xBABEL, 0xFACEL,
                0xFEEDL, 0xD00DL, 0xC0DEL, 0xACE2L, 0xBEADL };
        long acc = 0;
        for (int i = 0; i < seeds.length; i++) {
            acc ^= seeds[i] * (i + 1);
            acc *= 0x9E3779B97F4A7C15L;
            acc = (acc << (i % 7 + 1)) | (acc >>> (63 - i % 7));
        }
        return acc;
    }

    public static void main(String[] args) {
        long result = compute();
        long correct = correctCompute();
        if (result == correct) {
            throw new RuntimeException("AssertionError: early return gives same result: undetectable");
        }
        throw new IllegalArgumentException("ValueError: returned inside loop too early: got 0x"
                + Long.toHexString(result) + ", expected 0x" + Long.toHexString(correct));
    }
}

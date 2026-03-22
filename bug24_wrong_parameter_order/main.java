public class main {
    static long weighted_mix(long base, long weight, long offset) {
        long acc = base;
        for (long i = 0; i < 10; i++) {
            acc = (acc ^ (weight * i + offset)) * 0x9E3779B97F4A7C15L;
            long shiftLeft = i % 7 + 1;
            long shiftRight = 63 - (i % 7);
            acc = (acc << shiftLeft) | (acc >>> shiftRight);
        }
        return acc;
    }

    public static void main(String[] args) {
        long base_val   = 0xCAFEBABE12345678L;
        long weight_val = 0x100L;
        long offset_val = 0xDEADL;

        long correct = weighted_mix(base_val, weight_val, offset_val);
        long wrong   = weighted_mix(weight_val, base_val, offset_val);
        if (correct == wrong) {
            throw new AssertionError("parameter swap produces same result: undetectable");
        }
        throw new IllegalArgumentException(String.format("ValueError: wrong parameter order: got 0x%x instead of 0x%x", wrong, correct));
    }
}

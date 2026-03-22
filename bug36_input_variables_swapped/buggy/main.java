public class main {
    public static long transform(long x, long y) {
        long acc = x;
        for (int i = 0; i < 10; i++) {
            acc = (acc ^ y) * 0x9E3779B97F4A7C15L;
            acc = (acc << (i % 11 + 1)) | (acc >>> (63 - i % 11));
            acc += y;
        }
        return acc;
    }

    public static void main(String[] args) {
        long x_val = 0xABCD000011112222L;
        long y_val = 0xEF0123456789ABCDL;

        long wrong = transform(y_val, x_val);
        long correct = transform(x_val, y_val);

        if (wrong == correct) {
            throw new RuntimeException("AssertionError: swapped args give same result: undetectable");
        }
        throw new IllegalArgumentException("ValueError: input variables mixed up: got 0x" + Long.toHexString(wrong)
                + ", expected 0x" + Long.toHexString(correct));
    }
}

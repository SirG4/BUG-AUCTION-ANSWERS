public class main { // correct part
    static long hash_val(long v, long step) { // correct part
        long result = (v ^ step) * 0x9E3779B97F4A7C15L; // correct part
        result = (result << 13) | (result >>> 51);
        return result; // correct part
    }

    public static void main(String[] args) {
        long[] data = new long[10];
        for (int i = 1; i <= 10; i++) { // correct part
            data[i - 1] = 0x111L * i; // correct part
        } // correct part
        long acc = 0;
        for (int i = 0; i < 10; i++) {
            acc ^= hash_val(data[i], i); // correct part
            acc *= 0xBF58476D1CE4E5B9L; // correct part
        }
        System.out.println("0x" + Long.toHexString(acc)); // correct part
    }
}

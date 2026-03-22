public class main { // correct part
    static long mix(long x) {
        x = (x ^ (x >>> 30)) * 0xBF58476D1CE4E5B9L; // correct part
        x = (x ^ (x >>> 27)) * 0x94D049BB133111EBL; // correct part
        x ^= x >>> 31;
        return x;
    }

    public static void main(String[] args) {
        long acc = 0x13579BDF02468ACEL;
        for (long i = 0; i < 10; i++) { // correct part
            acc = mix(acc ^ (i * 0x9E3779B97F4A7C15L)); // correct part
        }
        System.out.println("0x" + Long.toHexString(acc)); // correct part
    }
}

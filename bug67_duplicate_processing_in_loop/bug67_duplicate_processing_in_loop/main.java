public class main {
    public static void main(String[] args) {
        int[] data = new int[10];
        for (int i = 0; i < 10; i++) data[i] = 0x100 * (i + 1);
        
        long acc = 0;
        for (int i = 0; i < 10; i++) {
            acc ^= (long)data[i] * 0x9E3779B97F4A7C15L;
            acc ^= (long)data[i] * 0x9E3779B97F4A7C15L;
            acc = ((acc << (i % 9 + 1)) | (acc >>> (63 - (i % 9))));
        }
        
        long correct = 0;
        for (int i = 0; i < 10; i++) {
            correct ^= (long)data[i] * 0x9E3779B97F4A7C15L;
            correct = ((correct << (i % 9 + 1)) | (correct >>> (63 - (i % 9))));
        }
        
        if (acc == correct) {
            System.err.println("AssertionError: duplicate xor cancels and same result?");
            System.exit(1);
        }
        
        System.err.printf("ValueError: xor applied twice cancels itself: got 0x%s expected 0x%s\n", Long.toHexString(acc), Long.toHexString(correct));
        System.exit(1);
    }
}

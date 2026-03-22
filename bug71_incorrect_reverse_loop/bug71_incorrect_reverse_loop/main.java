public class main {
    public static void main(String[] args) {
        long[] data = new long[10];
        for (int i = 0; i < 10; i++) data[i] = 0x100L * (i + 1);
        
        long acc = 0;
        for (int i = 9; i > 0; i--) {
            acc ^= data[i] * (i + 1);
            acc = (acc * 0x9E3779B97F4A7C15L);
            acc = ((acc << (i % 7 + 1)) | (acc >>> (63 - (i % 7))));
        }
        
        long correct = 0;
        for (int i = 9; i >= 0; i--) {
            correct ^= data[i] * (i + 1);
            correct = (correct * 0x9E3779B97F4A7C15L);
            correct = ((correct << (i % 7 + 1)) | (correct >>> (63 - (i % 7))));
        }
        
        if (acc == correct) {
            System.err.println("AssertionError: reverse loop stop same result");
            System.exit(1);
        }
        
        System.err.printf("ValueError: reverse loop stops at 1 not 0, skips index 0: got 0x%s expected 0x%s\n", Long.toHexString(acc), Long.toHexString(correct));
        System.exit(1);
    }
}

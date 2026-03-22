public class main {
    public static void main(String[] args) {
        int[] data = new int[20];
        for (int i = 0; i < 20; i++) data[i] = i;
        
        long acc = 0;
        for (int i = 0; i < 20; i += 3) {
            acc ^= (long)data[i] * 0x9E3779B97F4A7C15L;
            acc = ((acc << (i % 9 + 1)) | (acc >>> (63 - (i % 9))));
        }
        
        long correct = 0;
        for (int i = 0; i < 20; i += 2) {
            correct ^= (long)data[i] * 0x9E3779B97F4A7C15L;
            correct = ((correct << (i % 9 + 1)) | (correct >>> (63 - (i % 9))));
        }
        
        if (acc == correct) {
            System.err.println("AssertionError: step 3 same as step 2");
            System.exit(1);
        }
        
        System.err.printf("ValueError: step is 3 instead of 2: got 0x%s expected 0x%s\n", Long.toHexString(acc), Long.toHexString(correct));
        System.exit(1);
    }
}

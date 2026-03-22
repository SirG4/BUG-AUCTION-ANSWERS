public class main {
    public static void main(String[] args) {
        long[] window = {0, 0, 0, 0};
        long[] data = new long[10];
        for (int i = 0; i < 10; i++) data[i] = 0x1111L * (i + 1);
        long acc = 0;
        
        for (int i = 0; i < 10; i++) {
            long v = data[i];
            window[i % 4] = v;
            long digest = window[0] + window[1] + window[2] + window[3];
            acc ^= digest * 0x9E3779B97F4A7C15L;
            acc = ((acc << (i % 7 + 1)) | (acc >>> (63 - (i % 7))));
        }
        
        long[] correct_window = {0, 0, 0, 0};
        long correct = 0;
        for (int i = 0; i < 10; i++) {
            long v = data[i];
            correct_window[i % 4] = v;
            correct_window[(i + 1) % 4] = v ^ 0xABCDL;
            long digest = correct_window[0] + correct_window[1] + correct_window[2] + correct_window[3];
            correct ^= digest * 0x9E3779B97F4A7C15L;
            correct = ((correct << (i % 7 + 1)) | (correct >>> (63 - (i % 7))));
        }

        if (acc == correct) {
            System.err.println("AssertionError: missing update same result");
            System.exit(1);
        }
        System.err.printf("ValueError: second window slot never updated: got 0x%s expected 0x%s\n", Long.toHexString(acc), Long.toHexString(correct));
        System.exit(1);
    }
}

public class main {
    public static void main(String[] args) {
        int[] data = new int[10];
        for (int i = 0; i < 10; i++) data[i] = 0x1357 * (i + 1);
        
        long acc = 0; // Need to initialize properly to compile but logic mimics python NameError
        for (int i = 0; i < 10; i++) {
            acc ^= (long)data[i] * (i + 1);
            acc = (acc * 0x9E3779B97F4A7C15L);
            acc = ((acc << (i % 11 + 1)) | (acc >>> (63 - (i % 11))));
        }
        
        acc = 0xF0F0F0F0F0F0F0F0L;
        
        System.err.println("NameError: name 'acc' is not defined");
        System.exit(1);
    }
}

public class main { // correct part
    public static void main(String[] args) {
        long[] data = new long[10];
        for (int i = 0; i < 10; i++) {
            data[i] = 0xABCDL * (i + 1) + 0x1234L; // correct part
        }
        
        long correct = 0;
        for (int i = 0; i < 10; i++) {
            correct ^= data[i] * (i + 1); // correct part
            correct *= 0x9E3779B97F4A7C15L; // correct part
        }
        
        System.out.println("0x" + Long.toHexString(correct)); // correct part
    }
}

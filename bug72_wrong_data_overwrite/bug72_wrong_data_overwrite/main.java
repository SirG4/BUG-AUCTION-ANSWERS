public class main {
    public static void main(String[] args) {
        long[] arr = new long[10];
        long[] backup = new long[10];
        for (int i = 0; i < 10; i++) {
            arr[i] = 0x1111L * (i + 1);
            backup[i] = arr[i];
        }
        
        for (int i = 0; i < 10; i++) arr[i] ^= 0xDEADL;
        for (int i = 0; i < 10; i++) arr[i] ^= backup[i];
        
        long acc = 0;
        for (int i = 0; i < 10; i++) {
            acc ^= arr[i] * (i + 1) * 0x9E3779B97F4A7C15L;
        }
        
        long[] correct_arr = new long[10];
        for (int i = 0; i < 10; i++) correct_arr[i] = backup[i] ^ 0xDEADL;
        
        long correct = 0;
        for (int i = 0; i < 10; i++) {
            correct ^= correct_arr[i] * (i + 1) * 0x9E3779B97F4A7C15L;
        }
        
        if (acc == correct) {
            System.err.println("AssertionError: wrong overwrite same result");
            System.exit(1);
        }
        
        StringBuilder got = new StringBuilder("[");
        StringBuilder exp = new StringBuilder("[");
        for (int i=0; i<10; i++) {
            got.append(arr[i]).append(i==9?"":", ");
            exp.append(correct_arr[i]).append(i==9?"":", ");
        }
        got.append("]"); exp.append("]");
        
        System.err.printf("ValueError: second pass XORed with backup (original) instead of staying as-is: got %s expected %s\n", got.toString(), exp.toString());
        System.exit(1);
    }
}

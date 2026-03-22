public class main {
    public static void main(String[] args) {
        long fast = 0xAAAA0000BBBB1111L;
        long slow = 0xCCCC2222DDDD3333L;
        for (int i = 0; i < 10; i++) {
            fast ^= i * 0x9E3779B97F4A7C15L;
            fast = ((fast << (i % 9 + 1)) | (fast >>> (63 - (i % 9))));
            fast = (fast * 0xBF58476D1CE4E5B9L);
        }
        
        long correct_fast = 0xAAAA0000BBBB1111L;
        long correct_slow = 0xCCCC2222DDDD3333L;
        for (int i = 0; i < 10; i++) {
            correct_fast ^= i * 0x9E3779B97F4A7C15L;
            correct_fast = ((correct_fast << (i % 9 + 1)) | (correct_fast >>> (63 - (i % 9))));
            correct_slow = (correct_slow * 0xBF58476D1CE4E5B9L);
        }
        
        long final_val = fast ^ slow;
        long correct_final = correct_fast ^ correct_slow;
        
        if (final_val == correct_final) {
            System.err.println("AssertionError: wrong variable updated same result");
            System.exit(1);
        }
        System.err.printf("ValueError: slow variable never updated: got 0x%s expected 0x%s\n", Long.toHexString(final_val), Long.toHexString(correct_final));
        System.exit(1);
    }
}

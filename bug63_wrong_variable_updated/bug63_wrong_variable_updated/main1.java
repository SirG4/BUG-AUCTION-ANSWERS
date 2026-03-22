public class main1 {
    public static void main(String[] args) {
        long fast = 0xAAAA0000BBBB1111L;
        long slow = 0xCCCC2222DDDD3333L;

        for (int i = 0; i < 10; i++) {
            fast ^= i * 0x9E3779B97F4A7C15L;

            int shift = (i % 9 + 1);
            fast = (fast << shift) | (fast >>> (64 - shift)); // ✅ FIX

            slow = slow * 0xBF58476D1CE4E5B9L; // ✅ FIX: corrected variable
        }

        long final_val = fast ^ slow;

        System.out.println(Long.toHexString(final_val)); // ✅ Added output
    }
}
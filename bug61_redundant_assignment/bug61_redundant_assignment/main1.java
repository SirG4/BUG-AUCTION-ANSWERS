public class main1 {
   
    public static void main(String[] args) {
        long acc = 0x9191919191919191L;

        for (int i = 0; i < 10; i++) {

            // FIX: ensure i is treated as long BEFORE multiplication
            acc = (acc ^ ((long)i * 0x9E3779B97F4A7C15L));

            int shift = (i % 13 + 1);

            // FIX: ensure proper rotation (same as Python)
            acc = (acc << shift) | (acc >>> (64 - shift));

            // FIX: explicitly mask to 64-bit (important for consistency)
            acc = acc & 0xFFFFFFFFFFFFFFFFL;

            acc = acc * 0xBF58476D1CE4E5B9L;

            // FIX: mask after multiplication
            acc = acc & 0xFFFFFFFFFFFFFFFFL;
        }

        if (acc == 0x9191919191919191L) {
            System.err.println("Error: acc should not remain unchanged");
            System.exit(1);
        }

        System.out.println(Long.toHexString(acc));
    }
}


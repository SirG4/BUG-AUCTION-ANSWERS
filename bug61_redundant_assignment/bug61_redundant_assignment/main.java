public class main {
    public static void main(String[] args) {
        long acc = 0x9191919191919191L;
        for (int i = 0; i < 10; i++) {
            acc ^= i * 0x9E3779B97F4A7C15L;
            acc = ((acc << (i % 13 + 1)) | (acc >>> (63 - (i % 13))));
            acc = acc;
            acc = (acc * 0xBF58476D1CE4E5B9L);
            acc = 0x9191919191919191L;
        }
        
        if (acc == 0x9191919191919191L) {
            System.err.println("ValueError: redundant final assignment reset acc to seed each iteration");
            System.exit(1);
        }
    }
}

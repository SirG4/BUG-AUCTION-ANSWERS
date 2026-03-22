public class main1 {
    public static void main(String[] args) {
        int[] data = new int[0];
        int total = 0;

        for (int v : data) {
            total += v;
        }

        double avg;

        if (data.length == 0) {
            avg = 0; // ✅ FIX
        } else {
            avg = (double) total / data.length;
        }

        long acc = ((long) avg * 0x9E3779B97F4A7C15L);

        System.out.println(Long.toHexString(acc)); // ✅ Added output
    }
}
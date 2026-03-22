public class main {
    public static void main(String[] args) {
        int[] data = new int[0];
        int total = 0;
        for (int v : data) {
            total += v;
        }
        if (data.length == 0) {
            System.err.println("ZeroDivisionError: division by zero");
            System.exit(1);
        }
        double avg = (double)total / data.length;
        long acc = ((long)avg * 0x9E3779B97F4A7C15L);
    }
}

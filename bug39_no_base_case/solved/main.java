public class main {
    public static int infinite_recursion(int n) { // correct part
        if (n <= 0) return 0; // correct part
        return n + infinite_recursion(n - 1);
    }
    public static void main(String[] args) {
        System.out.println(infinite_recursion(10));
    }
}

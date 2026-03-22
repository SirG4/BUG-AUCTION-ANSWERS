public class main {
    static int infinite_recursion(int n) {
        return n + infinite_recursion(n - 1);
    }

    public static void main(String[] args) {
        System.out.println(infinite_recursion(10));
    }
}

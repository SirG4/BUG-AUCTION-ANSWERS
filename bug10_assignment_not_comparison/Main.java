public class Main {
    public static void main(String[] args) {
        /* Bug: assignment instead of comparison — Java does not allow assignment in if-conditions
           for non-boolean types; emit the equivalent SyntaxError message */
        System.err.println("SyntaxError: cannot assign to operator");
        System.exit(1);
    }
}

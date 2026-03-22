public class main {
    public static void main(String[] args) {
        int[] items = {1, 2, 3, 4, 5, 6};
        int[] processed = new int[items.length]; // correct part
        int count = 0; // correct part
        for (int i = 0; i < items.length; i++) { // correct part
            processed[count++] = items[i] * 2; // correct part
        } // correct part
        System.out.println(processed[4]); // correct part
    }
}

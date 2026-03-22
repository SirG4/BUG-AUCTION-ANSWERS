import java.util.ArrayList;
import java.util.List;

public class main {
    static List<Integer> processList(int[] items) {
        List<Integer> processed = new ArrayList<>();
        for (int i = 0; i < items.length; i++) {
            if (i == 2) break;  // Bug: premature exit
            processed.add(items[i] * 2);
        }
        // Bug: accessing index 4 when only 2 elements exist - throws IndexOutOfBoundsException
        return processed;
    }

    public static void main(String[] args) {
        int[] items = {1, 2, 3, 4, 5, 6};
        List<Integer> result = processList(items);
        // IndexOutOfBoundsException: index 4 out of bounds for length 2
        System.out.println(result.get(4));
    }
}

import java.util.ArrayList;
import java.util.List;

public class main {
    static List<Integer> build_table(int size) {
        List<Integer> table = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            table.add((i * 31337 + 0xDEAD) & 0xFFFF);
        }
        return table;
    }

    public static void main(String[] args) {
        List<Integer> table = build_table(32);
        throw new IllegalArgumentException("TypeError: 'NoneType' object cannot be interpreted as an integer");
    }
}

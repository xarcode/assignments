// display stars in a triangle form
public class Number12 {
    public static void main(String[] args) {
        int r = 5;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < i; j++) {
                System.out.print(" * ");
            }
            System.out.println();
        }
    }
}

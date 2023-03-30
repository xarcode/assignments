
// Java code to illustrate initialization
// of ArrayList using another collection
import java.util.*;

public class InitArr {
    public static void main(String args[]) {
        // create another collection
        List<Integer> arr1 = new ArrayList<>(10);
        List<Integer> arr = new ArrayList<>();
        arr.add(1);
        arr.add(2);
        // create a ArrayList Integer type
        // and Initialize an ArrayList with arr
        List<Integer> new_arr = new ArrayList<Integer>(arr);
        // print ArrayList
        System.out.println("ArrayList : " + new_arr);
    }
}

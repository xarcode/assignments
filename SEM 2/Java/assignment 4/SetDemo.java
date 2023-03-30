
// Java code to illustrate remove() method
import java.util.*;

public class SetDemo {
    public static void main(String args[]) {
        // Creating an empty Set
        Set<String> set = new HashSet<String>();
        // Use add() method to add elements into the Set
        set.add("a");
        set.add("super");
        set.add("hero");
        // Displaying the Set
        System.out.println("Set: " + set);
        // Removing elements using remove() method
        set.remove("super");
        // Displaying the Set after removal
        System.out.println("Set after removing elements: " + set);
    }
}
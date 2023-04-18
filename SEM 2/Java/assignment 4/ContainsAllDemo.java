
// Java code to illustrate containsAll() method
import java.util.*;

public class ContainsAllDemo {
    public static void main(String args[]) {
        // Creating an empty list
        Queue<String> q = new LinkedList<String>();
        // Use add() method to add elements into the List
        q.add("how");
        q.add("are");
        q.add("you");
        // Displaying the queue
        System.out.println("queue: " + q);
        // Creating another empty queue
        Queue<String> qTemp = new LinkedList<String>();
        qTemp.add("how");
        qTemp.add("are");
        System.out.println("Are all the contents equal? " + q.containsAll(qTemp));
    }
}
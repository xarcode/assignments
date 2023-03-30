
// Java Program to illustrate the stack toArray() method in Java
import java.util.*;

public class ToArray {
    public static void main(String[] args) {
        // create object of stack
        Stack<Integer> stack = new Stack<Integer>();
        // Add elements
        stack.add(32);
        stack.add(67);
        // print ArrayList
        System.out.println("stack: " + stack);
        // Get the array of the elements
        // of the stack
        // using toArray() method
        Object[] arr = stack.toArray();
        System.out.println("Elements of stack" + " as Array: " + Arrays.toString(arr));
    }
}
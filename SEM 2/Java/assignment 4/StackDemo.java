
// Java program to show the addAll
// of the elements from the stack
import java.util.*;
import java.io.*;

public class StackDemo {
    // Main Method
    public static void main(String args[]) {
        // Creating an empty Stack
        Stack<String> stack = new Stack<String>();
        Stack<String> stack1 = new Stack<String>();
        // Use push() to add elements into the Stack
        stack1.add("ayush");
        stack.add("nandi");
        stack.addAll(stack1);
        // Fetching the element at the head of the Stack
        System.out.println("The element at the top of the"
                + " stack is: " + stack.peek());
    }
}
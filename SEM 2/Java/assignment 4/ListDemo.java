
// Java program to Demonstrate List Interface
// Importing all utility classes
import java.util.*;

class ListDemo {
    public static void main(String[] args) {
        List<Integer> l1 = new ArrayList<Integer>();
        l1.add(0, 1);
        System.out.println(l1);// Print the elements inside the object
        List<Integer> l2 = new ArrayList<Integer>();
        l2.add(1);
        l1.addAll(1, l2);// Will add list l2 from 1 index
        System.out.println(l1);
        l1.remove(1);// Removes element from index 1
        System.out.println(l1);// Printing the updated List 1
        System.out.println(l1.get(0));// Prints element at index 3 in list 1// using get() method
        l1.set(0, 5); // Replace 0th element with 5// in List 1
        System.out.println(l1);// Again printing the updated List 1
    }
}

// Java code to illustrate the use of iterator
import java.io.*;
import java.util.*;

class Test {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<String>();
        list.add("A");
        list.add("B");
        list.add("C");
        // Iterator to traverse the list
        Iterator iterator = list.iterator();
        System.out.println("List elements : ");
        while (iterator.hasNext())
            System.out.print(iterator.next() + " ");
        System.out.println();
    }
}
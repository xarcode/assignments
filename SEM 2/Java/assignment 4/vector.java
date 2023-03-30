
// Java Program of Vector Class
import java.io.*;
import java.util.*;

class vector {
    public static void main(String[] arg) {
        Vector v1 = new Vector();
        v1.add(1);// using add() method
        v1.add(2);
        v1.add(3);
        System.out.println("Vector v1 is " + v1);// Printing the vector elements to the console
        Vector<Integer> v2 = new Vector<Integer>();
        v2.add(1);
        v2.add(2);
        v2.add(3);
        System.out.println("Vector v2 is " + v2);
    }
}
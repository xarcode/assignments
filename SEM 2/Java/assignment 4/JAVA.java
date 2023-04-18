import java.util.*;

class JAVA {
    public static void main(String args[]) {
        Queue<Integer> Queue = new LinkedList<Integer>();
        // adding elements to Queue
        Queue.add(1);
        Queue.add(3);
        Queue.add(5);
        Queue.add(2);
        Queue.add(0);
        // filed queue
        System.out.println("The Queue is empty: " + Queue.isEmpty());
        Queue<Integer> Queue_2 = new LinkedList<Integer>();
        // empty queue
        System.out.println("The Queue_2 is empty: " + Queue_2.isEmpty());
    }
}
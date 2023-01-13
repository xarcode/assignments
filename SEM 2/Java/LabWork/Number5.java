// find the difference bewteen the pre and post increment of a and b
public class Number5 {
    public static void main(String[] args) {
        int a = 1, b = 2;
        a = ++b;
        
        System.out.println("a = ++b");
        System.out.println(a);
        System.out.println(b);
        
        a = 1;
        b = 2;
        System.out.println("a = b++");
        a = b++;
        System.out.println(a);
        System.out.println(b);
    }
}

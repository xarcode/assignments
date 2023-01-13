// display numbers form 1 to 10 using infinite for loop
public class Number11 {
    public static void main(String[] args) {
        int x = 1;
        for(; ;){
            System.out.println(x++);
            if(x > 10) break;
        }
    }
}

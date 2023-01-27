import java.io.*;

public class Assignment1 {

    static int fact(int n){
        if(n < 2) return 1;
        return n * fact(n - 1);
    }

    static String reverse(String s){
        String res = "";
        for (int i = s.length() - 1; i >= 0; i--) res += s.charAt(i);

        return res;
    }
    public static void main(String[] args) throws IOException {
        double y = 1;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter value of n ");
        int n = Integer.parseInt(br.readLine());
        System.out.print("Enter value of x ");
        float x = Float.parseFloat(br.readLine());

        System.out.print("Result of y is ");
        for (int i = 1; i < n; i++)
            y += Math.pow(-1, i) * Math.pow(x, 2 * i) / fact(2 * i);

        System.out.println(y);

        System.out.print("Enter a string: ");
        System.out.println(reverse(br.readLine()));
    }
}

// y = 1 - x^2/2! + x^4/4! - ...
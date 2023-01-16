import java.io.*;

public class SimpleCalculator {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Enter 2 numbers");
        float n1 = Float.parseFloat(br.readLine());
        float n2 = Float.parseFloat(br.readLine());
        float res;

        System.out.println("Enter an operator (+, -, * or /)");
        char op = (char) br.read();

        switch (op) {
            case '+':
                res = n1 + n2;
                break;
            case '-':
                res = n1 - n2;
                break;
            case '*':
                res = n1 * n2;
                break;
            case '/':
                if (n2 == 0) {
                    System.out.println("Divide by 0 error");
                    return;
                }
                res = n1 / n2;
                break;
            default:
                System.out.println("Invalid opertor...");
                return;
                // break;
        }

        System.out.println(n1 + " " + op + " " + n2 + " = " + res);
    }
}

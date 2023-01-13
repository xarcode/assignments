import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Number26 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        double n = Double.parseDouble(br.readLine());
        System.out.println("You entered " + n);
    }
}

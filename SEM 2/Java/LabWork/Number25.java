import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Number25 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        float n = Float.parseFloat(br.readLine());
        System.out.println("You entered " + n);
    }
}

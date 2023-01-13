import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Number23 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter a name: ");
        String str = br.readLine();
        System.out.println("You Entered " + str);
    }
}

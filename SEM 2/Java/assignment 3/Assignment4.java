import java.io.*;

public class Assignment4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));        
        String inp = br.readLine();

        int sum = 0;
        for (int i = 0; i < inp.length(); i++) {
            if(inp.charAt(i) >= '0' && inp.charAt(i) <= '9')
                sum += (inp.charAt(i) - '0');
        }

        System.out.println(sum);
    }
}

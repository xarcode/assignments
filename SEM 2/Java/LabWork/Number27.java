import java.io.*;

public class Number27 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter id: ");
        int id = Integer.parseInt(br.readLine());
        System.out.print("Enter sex: ");
        char sex = (char)br.read();
        br.skip(2);
        System.out.print("Enter name: ");
        String name = br.readLine();

        System.out.println("Id: " + id);
        System.out.println("Sex: " + sex);
        System.out.println("Name: " + name);
    }
}

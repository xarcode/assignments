import java.io.DataInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class WriteintoFile {
    public static void main(String[] args) throws IOException{
    DataInputStream dis = new DataInputStream(System.in);
    FileOutputStream FoS = new FileOutputStream("demo.txt");
    System.out.println("Enter text ($ at end):");
    char ch;

    while((ch = (char)dis.read())!= '$')
    {
        FoS.write(ch);
    }
    FoS.close();
    }
}

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;

public class readFile {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter file name: ");
        String fname = br.readLine();

        FileInputStream fil = null;

        try {
            fil = new FileInputStream(fname);
        } catch (FileNotFoundException fe) {
            System.out.println("File not Found!");
            return;
        }

        BufferedInputStream bin = new BufferedInputStream(fil);
        int ch;
        while((ch = bin.read())!= -1)
            System.out.print((char)ch);
        
        bin.close();
    }
}

import java.io.*;
import java.util.zip.DeflaterOutputStream;

public class ZipingUsingdeflater {
    public static void main(String[] args) throws IOException {
        FileInputStream fis = new FileInputStream("demo.txt");

        FileOutputStream fos = new FileOutputStream("demo.zip");
        DeflaterOutputStream dos = new DeflaterOutputStream(fos);

        int data;
        while((data = fis.read()) != -1)
        dos.write(data);
        fis.close();
        dos.close();    
    }
}
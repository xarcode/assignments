import java.io.FileInputStream;
import java.io.IOException;

class readData{
    public static void main(String[] args) throws IOException{
        FileInputStream fin = new FileInputStream("demo.txt");

        int ch;
        while((ch = fin.read())!= -1)
        {
            System.out.print((char)ch);
        }
        fin.close();
    }
}
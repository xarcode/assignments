import java.io.*;

public class createFileUsingfileWrite {
    public static void main(String[] args)throws IOException {
        String str = "This is MCA.\nI am learner of MCA"; 
        FileWriter fw = new FileWriter("demo.txt", true);
        for(int i = 0; i < str.length(); i++)
        {
            fw.write(str.charAt(i));
        }
        fw.close();
    }
}

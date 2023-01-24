import java.util.*;

public class cw {

    public static void main(String[] args) {
        String cppCode = "void print(){\ncout<<\"HELLO WORLD\";\n}";

        StringTokenizer st = new StringTokenizer(cppCode, "\n");

        int n = st.countTokens();

        String lines[] = new String[n];

        for (int i = 0; i < lines.length; i++) {
            lines[i] = st.nextToken();
        }

        String javaCode = "public static " + lines[0] + "\n";

        for(int i = 1; i < lines.length - 1; i++){
            lines[i] = lines[i].replaceFirst("cout<<", "System.out.println(");
            lines[i] = lines[i].replaceFirst(";", "");
            javaCode += (lines[i] + ");\n");
        }

        javaCode += lines[lines.length - 1];

        System.out.println(javaCode);
    }
}
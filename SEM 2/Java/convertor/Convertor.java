import java.util.*;
import java.io.*;

public class Convertor {

    public static void main(String args[]) throws IOException {
        /*
         * C++ CODE
            int takeInput(){
            int n;
            cin >> n;
            return n;
            }
         */

         String cppCode = "int takeInput(){\nint n;\ncin >> n;\nreturn n;\n}";
         GetJavaCode obj = new GetJavaCode(cppCode);

        // char dt = 'i';
        System.out.println("Enter class name");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String className = br.readLine();
        System.out.println(obj.generateJavaCode(className));

    }
}

class GetJavaCode {

    public boolean hasCin;
    public String cppCode;

    public GetJavaCode(String s){
        hasCin = false;
        cppCode = s;
    }

    public String getJavaFunctionName(String line) {
        String res = "public static " + line + "\n";
        return res;
    }

    public String generateClassName(String className) {
        // className = className.replaceFirst("{", "");
        String res = "public class " + className;
        // if(hasCin) res += " throws IOException ";
        res += "{\n";
        return res;
    }

    // public String generateHeaderFiles(){

    // }

    public String getJavaInputMethod(char dataType, String varName){
        String res = "BufferedReader br = new BufferedReader(new InputStreamReader(System.in));";
        res += "\n";

        switch(dataType){
            case 'i':
                res += varName + " = Integer.parseInt(br.readLine());";
                break;
            case 'f':
                res += varName + " = Float.parseFloat(br.readLine());";
                break;
            case 'c':
                res += varName + " = br.readLine().charAt(0)";
                break;
            }
        
        // res = res.replaceFirst("varName", varName) + "\n";
        res += "\n";

        return res;
        
    }

    public boolean hasVariableDeclaration(String str){
        if(str.indexOf("int", 0) != -1 || str.indexOf("float", 0) != -1 || str.indexOf("char", 0) != -1 ){
            return true;
        }

        return false;
    }
    public boolean hasCinStatement(String str){
        if(str.indexOf("cin", 0) != -1){
            hasCin = true;
            return true;
        }

        return false;
    }

    public String[] getLinesOfCode(String cppCode) {
        StringTokenizer st = new StringTokenizer(cppCode, "\n");
        int n = st.countTokens();
        String lines[] = new String[n];
        for (int i = 0; i < n; i++) {
            lines[i] = st.nextToken();
        }

        return lines;
    }

    public char getDataType(String str){
        char c = 't';
        if(str.indexOf("int", 0) != -1)
            c = 'i';
        else if(str.indexOf("float", 0) != -1)
            c = 'f';
        else if(str.indexOf("char", 0) != -1)
            c = 'c';

        return c;
    }

    public String getVarName(String str){
        StringTokenizer st = new StringTokenizer(str, " ");
        st.nextToken();

        return st.nextToken().replaceFirst(";", "");
    }

    public String convertFunctionToJava(String lines[]){
        String res = getJavaFunctionName(lines[0]);
        char dt = 't';
        String varName = "";

        for (int i = 1; i < lines.length; i++) {
            if(hasVariableDeclaration(lines[i])){
                dt = getDataType(lines[i]);
                varName = getVarName(lines[i]);
                res += lines[i] + "\n";
            }
            else if(hasCinStatement(lines[i])){
                res += getJavaInputMethod(dt, varName);
            }
            else res += lines[i] + "\n";
        }
        return res;
    }

    public String generateJavaCode(String className){
    // public String generateJavaCode(String cppCode, String className){
        String[] lines = getLinesOfCode(cppCode);

        
        String javaCode = "";
        String functionCode = convertFunctionToJava(lines);

        String classDeclarationStatement = generateClassName(className);

        javaCode = classDeclarationStatement + functionCode + "\n}";

        return javaCode;
    }
}


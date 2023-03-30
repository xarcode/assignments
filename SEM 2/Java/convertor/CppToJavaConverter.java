import java.util.Scanner;
import java.util.StringTokenizer;

public class CppToJavaConverter {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the name of the Java class: ");
        String className = input.nextLine();

        String cppCode = "int add(int a, int b) {\n" +
                         "   return a + b;\n" +
                         "}\n\n" +
                         "int main() {\n" +
                         "   int x, y;\n" +
                         "   cin >> x >> y;\n" +
                         "   int sum = add(x, y);\n" +
                         "   cout << \"Sum: \" << sum << endl;\n" +
                         "   return 0;\n" +
                         "}";
        System.out.println("C++ code to convert:\n" + cppCode);

        String javaCode = convertCppToJava(cppCode);
        javaCode = "public class " + className + " {\n" + javaCode + "}";

        System.out.println("\nJava code:\n" + javaCode);
    }

    public static String convertCppToJava(String cppCode) {
        StringTokenizer st = new StringTokenizer(cppCode, ";");

        String javaCode = "";
        while (st.hasMoreTokens()) {
            String token = st.nextToken().trim();

            if (token.startsWith("#")) {
                // Skip preprocessor directives
                continue;
            } else if (token.startsWith("using")) {
                // Skip namespace declarations
                continue;
            } else if (token.startsWith("int main")) {
                javaCode += "public static void main(String[] args) {\n";
            } else if (token.contains("(") && token.contains(")")) {
                // Convert function to method
                int openParenIndex = token.indexOf("(");
                String functionName = token.substring(0, openParenIndex).trim();
                javaCode += "public static int " + functionName + "(";

                String params = token.substring(openParenIndex + 1, token.indexOf(")"));
                if (!params.trim().isEmpty()) {
                    String[] paramList = params.split(",");
                    for (int i = 0; i < paramList.length; i++) {
                        String[] paramTokens = paramList[i].trim().split(" ");
                        if (paramTokens.length >= 2) {
                            javaCode += paramTokens[paramTokens.length - 1] + " " + paramTokens[paramTokens.length - 2];
                            if (i != paramList.length - 1) {
                                javaCode += ", ";
                            }
                        }
                    }
                }
                javaCode += ") {\n";
            } else if (token.startsWith("cin")) {
                javaCode += "Scanner input = new Scanner(System.in);\n";
                javaCode += token.substring(4) + " = input.nextInt();\n";
            } else if (token.startsWith("cout")) {
                javaCode += "System.out.println(" + token.substring(5) + ");\n";
            }
        }

        javaCode += "}\n"; // Close method

        return javaCode;
    }
}

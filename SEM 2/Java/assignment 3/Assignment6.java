public class Assignment6 {
    static String rotate(String s, int d){
        int n = s.length();
        d %= n;
        String res = "";
        for(int i = n - d; i < n; i++)
            res += s.charAt(i);
        
        for (int i = 0; i < n - d; i++) {
            res += s.charAt(i);
        }

        return res;
    }    

    public static void main(String[] args) {
        System.out.println(rotate("apple", 6));
    }
}

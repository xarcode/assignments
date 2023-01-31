class Main {
    public static void main(String[] args) {
        String pal = "madam";
        String nPal = "warangal";

        PalindromeChecker pc = new PalindromeChecker();

        if (pc.check(pal))
            System.out.println(pal + " is a Palindrome");
        else
            System.out.println(pal + " is a not Palindrome");

        if (pc.check(nPal))
            System.out.println(nPal + " is a Palindrome");
        else
            System.out.println(nPal + " is a not Palindrome");
    }
}

class StringReverse {
    public String reverse(String s) {
        String reversed_str = "";

        for (int i = s.length() - 1; i >= 0; i--)
            reversed_str += s.charAt(i);
        return reversed_str;
    }
}

class PalindromeChecker {
    public boolean check(String str) {
        return (str.equals(new StringReverse().reverse(str)));
    }
}

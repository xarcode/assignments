class Main{
    public static void main(String[] args) {
        String str = "string1";
        StringReverse sr = new StringReverse();

        System.out.println("Reverse of " + str + " is " + sr.reverse(str));
    }
}

class StringReverse {
    public String reverse(String s){
        String reversed_str = "";

        for (int i = s.length() - 1; i >= 0; i--) reversed_str += s.charAt(i);
        return reversed_str;
    }    
}

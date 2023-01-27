public class Assignment7 {
    static int sumDigits(int n){
        int sum = 0;
        while(n != 0){
            sum += (n % 10);
            n /= 10;
        }

        return sum;
    }
    static int digitalRoot(int n){
        if(n / 10 == 0) return n;
        return digitalRoot(sumDigits(n));
    }    

    public static void main(String[] args) {
        int n = 1728;
        System.out.println("Digital root of " + n + " is " + digitalRoot(n));
    }
}

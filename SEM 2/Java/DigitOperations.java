class Main{
    public static void main(String[] args) {
        int n = 98765;
        DigitOperations d = new DigitOperations();
        d.separate(n);
        System.out.println("Sum of digits of " + n + " is " + d.sumDigits(n));
        System.out.println("Reversing digits of " + n + " is " + d.reverseDigits(n));

        if(d.isPalindrome(n))
            System.out.println(n + " is a palindrome");
        else
            System.out.println(n + " is not a palindrome");
    }
}

class DigitOperations{
	public void separate(int n){
		System.out.print("Separating the digits of " + n + ": ");
        int divisor = (int)Math.pow(10, (int)Math.log10(n));
		while (n > 0) {
            int digit = n / divisor;
            System.out.print(digit + " ");
            n %= divisor;
            divisor /= 10;
        }
        System.out.println();
	}

    public int sumDigits(int n){
        int sum = 0;
        while (n > 0) {
            int remainder = n % 10;
            sum += remainder;
            n = n / 10;
        }

        return sum;
    }
    
    public int reverseDigits(int n){
        int res = 0;
        int mul = (int)Math.pow(10, (int)Math.log10(n));
        while (n > 0) {
            int remainder = n % 10;
            res += remainder * mul;
            n /= 10;
            mul /= 10;
        }

        return res;
    }

    public boolean isPalindrome(int n){
        return n == reverseDigits(n);
    }
}
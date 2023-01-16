public class BasicPrograms{
	public static void main(String args[]){
		Factorial f = new Factorial();
		System.out.println("Factorial of 5 is " + f.fact(5));

		Prime p = new Prime();
		System.out.println("Is 25 a prime number? " + p.isPrime(25));
		System.out.println("Is 23 a prime number? " + p.isPrime(23));

		DigitSeparator ds = new DigitSeparator();
		ds.separate(909);

		Palindrome pl = new Palindrome();
		System.out.println("Is 'madam' a palindrome?");
		if(pl.isPalindrome("madam"))
			System.out.println("Yes");
		else
			System.out.println("No");
	}
}

class Factorial{
	public int fact(int n){
		if(n < 2) return 1;
		return n * fact(n - 1);
	}
}

class Prime{
	public String isPrime(int n){
		for(int i = 2; i * i <= n; i++)
			if(n % i == 0)
				return "not prime";
		
		return "prime";
	}
}

class Palindrome{
	public boolean isPalindrome(String s){
		for(int i = 0, j = s.length() - 1; i <= j; i++, j--)
			if(s.charAt(i) != s.charAt(j)) return false;

		return true;
	}
}

class DigitSeparator{
	public void separate(int n){
		System.out.println("Separating the digits of " + n);
		while (n > 0) {
            int remainder = n % 10;
            System.out.println(remainder);
            n = n / 10;
        }
	}
}
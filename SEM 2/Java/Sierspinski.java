class Sierpinski
{
	static void printSierpinski1(int n)
	{
		for (int y = n - 1; y >= 0; y--) {

			for (int i = 0; i < y; i++) {
				System.out.print(" ");
			}

			for (int x = 0; x + y < n; x++) {
				if ((x & y) != 0)
					System.out.print(" "
									+ " ");
				else
					System.out.print("* ");
			}

			System.out.print("\n");
		}
	}

    static void printSierpinski(int n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || (i & j) != 0)
                    System.out.print("*");
                else 
                    System.out.print(" ");
            }
            System.out.println();
        }
    }

	public static void main(String args[])
	{
		int n = 4;
		printSierpinski(n);
	}
}
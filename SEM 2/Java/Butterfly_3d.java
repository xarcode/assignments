class Butterfly_3d{
	public static void main(String args[]){
		int i = 0, j = 0, k, n = 5;
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++)
				if(j <= i) System.out.print("* ");
				else System.out.print("  ");
			for(k = n - 3; k > i - 2; k--)
				System.out.print("  ");
			for(k = k; k >= 0; k--)
				System.out.print("* ");
			System.out.println();
		}

		for(i = i - 2; i >= 0; i--){
			for(j = 0; j < n; j++)
				if(j <= i) System.out.print("* ");
				else System.out.print("  ");
			for(k = n - 3; k > i - 2; k--)
				System.out.print("  ");
			for(k = k; k >= 0; k--)
				System.out.print("* ");
			System.out.println();
		}
	}
}
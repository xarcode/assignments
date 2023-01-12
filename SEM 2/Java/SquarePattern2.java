class SquarePattern2{
	public static void main(String args[]){
		int n = 7;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if( i < 2 || i >= n - 2 || j < 2 || j >= n - 2)
					System.out.print("| ");
				else
					System.out.print("  ");
			}
			System.out.println();
		}
	}
}
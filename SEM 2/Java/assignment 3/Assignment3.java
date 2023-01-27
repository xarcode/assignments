public class Assignment3 {
    static boolean isSymmetric(int[][] mat){
        int N = mat.length;
        int M = mat[0].length;
        int transpose[][] = new int[M][N];

        if(N != M) return false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                transpose[j][i] = mat[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(transpose[i][j] != mat[i][j]) return false;
            }
        }

        return true;
    }
    public static void main(String[] args) {
        int mat[][] = {
            {1, 2, 3},
            {5, 4, 2},
            {3, 2, 1}
        };

        System.out.println(isSymmetric(mat));
    }    
}

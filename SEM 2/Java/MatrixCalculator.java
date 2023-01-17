public class MatrixCalculator {
    static int[][] multiply(int[][] m1, int[][] m2){
        int r1 = m1.length, c1 = m1[0].length;
        int r2 = m2.length, c2 = m2[0].length;
        
        if(c1 != r2)
        return new int[1][1];
        
        int[][] m3 = new int[r1][c2];
        
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                for (int k = 0; k < r2; k++)
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
        
        return m3;
    }
    
    static int[][] add(int[][] m1, int[][] m2){
        int r1 = m1.length, c1 = m1[0].length;

        int[][] m3 = new int[r1][c1];

        for (int i = 0; i < m3.length; i++) 
            for (int j = 0; j < m3[0].length; j++) 
                m3[i][j] = m1[i][j] + m2[i][j];
        
        return m3;
    }

    static int[][] sub(int[][] m1, int[][] m2){
        int r1 = m1.length, c1 = m1[0].length;

        int[][] m3 = new int[r1][c1];

        for (int i = 0; i < m3.length; i++) 
            for (int j = 0; j < m3[0].length; j++) 
                m3[i][j] = m1[i][j] - m2[i][j];
        
        return m3;
    }

    static void printMatrix(int[][] mat){
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat.length; j++) {
                System.out.print(mat[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        // expression -> (a * b) - c * d - (a * c)
        int a[][] = {
            {3, 2, 1},
            {4, 3, 5},
            {3, 1, 7}
        };
        int b[][] = {
            {7, 6, 1},
            {1, 7, 8},
            {2, 1, 9}
        };
        int c[][] = {
            {1, 2, 7},
            {5, 4, 4},
            {2, 1, 8}
        };
        int d[][] = {
            {6, 2, 7},
            {8, 3, 4},
            {1, 2, 3}
        };

        int[][] res = sub(sub(multiply(a, b), multiply(c, d)), multiply(a, c));

        printMatrix(res);
    }
}

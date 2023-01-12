public class JavaMethods {

    static void passingArray1(int array[]){
        System.out.println("Length of 1D array is " + array.length);
    }

    static void passingArray2(int matrix[][]){
        System.out.println("Dimension of matrix is " + matrix.length + "x" + matrix[0].length);
    }
    
    static void passingArray3(int multiDimensionArray[][][]){
        System.out.println("Dimension of matrix is " + multiDimensionArray.length + "x" + multiDimensionArray[0].length + "x" + multiDimensionArray[0][0].length);
    }

    static void passingObject(A obj){
        obj.print();
    }

    static int square(int a){
        return a * a;
    }

    static int cube(int a){
        return a * a * a;
    }

    public static void main(String[] args) {
        int[] array = new int[5];
        int[][] matrix = new int[5][6];
        int[][][] multiDimensionArray = new int[5][6][7];
        passingArray1(array);
        passingArray2(matrix);
        passingArray3(multiDimensionArray);

        A a = new A();

        passingObject(a);
    }
}

class A{
    private int a;

    public A(){
        a = 10;
    }

    public void print(){
        System.out.println("The value of a is " + a);
    }
}
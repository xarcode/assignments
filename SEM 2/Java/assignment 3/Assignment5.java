public class Assignment5 {
    static void swapArr(int[] arr1, int[] arr2){
        int temp[] = new int[arr1.length];

        for (int i = 0; i < arr2.length; i++) {
            temp[i] = arr2[i];
        }

        for (int i = 0; i < arr2.length; i++) {
            arr2[i] = arr1[i];
        }

        for (int i = 0; i < temp.length; i++) {
            arr1[i] = temp[i];
        }
    }    

    public static void main(String[] args) {
        int arr1[] = {1, 2, 3, 4}, arr2[] = {5, 6, 7, 8};
        swapArr(arr1, arr2);
        for (int i : arr1) {
            System.out.print(i + " ");
        }
        
        System.out.println();
        for (int i : arr2) {
            System.out.print(i + " ");
        }

        System.out.println();
    }
}

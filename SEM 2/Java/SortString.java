class Main {
    public static void main(String[] args) {
        String arr[] = { "ayush", "nandi", "nit", "mca", "warangal", "artifical", "intelligence" };

        new SortString().BubbleSort(arr);

        for (String string : arr) {
            System.out.println(string);
        }
    }
}

class SortString {
    public void BubbleSort(String arr[]) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (arr[j].compareTo(arr[j + 1]) > 0) {
                    String temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
    }
}
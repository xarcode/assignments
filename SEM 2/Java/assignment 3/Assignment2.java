import java.io.BufferedReader;
import java.io.*;

public class Assignment2 {
    static int insert(int arr[], int N, int x) {
        int temp[] = new int[N + 1];
        int j = 0, idx = 0, i = 0;

        while (i < N) {
            if (arr[i] < x)
                temp[j++] = arr[i++];
            else {
                idx = j;
                temp[j++] = x;
                break;
            }
        }

        while (i < N) {
            temp[j++] = arr[i++];
        }

        for (int k = 0; k < N + 1; k++) {
            arr[k] = temp[k];
        }
        return idx;
    }

    public static void main(String[] args) throws IOException {
        int arr[] = new int[100];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter size of array ");
        int N = Integer.parseInt(br.readLine());
        System.out.println("Enter a sorted array ");
        for (int i = 0; i < N; i++)
            arr[i] = Integer.parseInt(br.readLine());

        System.out.println("New element has been inserted at index " + insert(arr, N, 4));

        for (int k = 0; k < N + 1; k++)
            System.out.print(arr[k] + " ");
        System.out.println();
    }
}

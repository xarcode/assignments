import java.io.*;

class MagicSquare {
    static boolean isCorner(int i, int j) {
        if ((i == 0 || i == 2) && (j == 0 || j == 2))
            return true;
        return false;
    }

    static int[] getPair(int n) {

        int[] arr = new int[2];
        switch (n) {
            case 2:
                arr[0] = 7;
                arr[1] = 9;
                break;
            case 4:
                arr[0] = 3;
                arr[1] = 9;
                break;
            case 6:
                arr[0] = 7;
                arr[1] = 1;
                break;
            case 8:
                arr[0] = 3;
                arr[1] = 1;
                break;
        }

        return arr;
    }

    static boolean search(int arr[], int key) {
        for (int i = 0; i < arr.length; i++) {
            if (key == arr[i])
                return true;
        }
        return false;
    }

    static int[][] makeMagic(int arr[][]) {

        arr[0][2] = 15 - arr[0][0] - arr[0][1];
        arr[2][0] = 15 - arr[1][1] - arr[0][2];
        arr[1][0] = 15 - arr[0][0] - arr[2][0];
        arr[2][1] = 15 - arr[0][1] - arr[1][1];
        arr[2][2] = 15 - arr[0][0] - arr[1][1];
        arr[1][2] = 15 - arr[0][2] - arr[2][2];

        return arr;
    }

    public static void main(String ars[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] pair = { 0, 0 };
        // int cornerEle[] = {2, 4, 6, 8};
        // int doneIn
        int arr[][] = {
                { 0, 0, 0 },
                { 0, 5, 0 },
                { 0, 0, 0 }
        };

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print("Enter value for element " + "[" + i + ", " + j + "] - ");
                int ele = Integer.parseInt(br.readLine());
                if (ele < 1 || ele > 9) {
                    System.out.println("Please enter numbers within 1 to 9");
                    j--;
                    continue;
                }
                if (i == 0 && j < 2) {
                    if (isCorner(i, j)) {
                        if (ele % 2 == 0) {
                            arr[i][j] = ele;
                            pair = getPair(ele);
                        } else if (i == 0 && j == 0) {
                            System.out.println("Wrong input! It can either be 2, 4, 6 and 8");
                            j--;
                            continue;
                        } else
                            System.out.println("pass");
                    } else {
                        if (ele % 2 == 1) {
                            if (!search(pair, ele)) {
                                System.out.print("Wrong input! It can be ");
                                for (int k = 0; k < pair.length; k++) {
                                    System.out.print(pair[k] + " ");
                                }
                                System.out.println();
                                j--;
                                continue;
                            } else
                                arr[i][j] = ele;
                        } else {
                            System.out.println("Wrong INput! It can be 1, 3, 7 or 9");
                            j--;
                            continue;
                        }
                    }

                    if (i == 0 && j == 1) {
                        arr = makeMagic(arr);
                    }
                } else {
                    if (ele != arr[i][j]) {
                        System.out.println("Wrong input! It can be " + arr[i][j]);
                        j--;
                        continue;
                    }
                }
            }
        }

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }
}
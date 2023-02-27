import java.util.Scanner;

public class tictactoe {
    public static void main(String[] args) {
        char arr[][] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
        System.out.println("\n--------------------TIC TAC TOE--------------------\n");
        System.out.println("\n-------------");
        for (int i = 0; i < 3; i++) {
            System.out.print("| ");
            for (int j = 0; j < 3; j++) {
                System.out.print(arr[i][j]);
                System.out.print(" | ");
            }
            System.out.println("\n-------------");
        }
        int currentplayer = 1;
        Scanner sc = new Scanner(System.in);
        while (true) {
            if (currentplayer == 1) {
                System.out.println("\n----------Player 1's Turn----------\n");
                while (true) {
                    System.out.print("Enter the place where you want to insert X : (1-9) : ");
                    int p = sc.nextInt();
                    if (!(p >= 1 || p <= 9)) {
                        System.out.println("\nWrong input given ! please try again");
                        continue;
                    }

                    int x, y;
                    y = (p - 1) / 3;
                    x = (p - 1) % 3;
                    if (arr[y][x] == ' ') {
                        arr[y][x] = 'X';
                        break;
                    } else {
                        System.out.println("\nThis place is already filled - please try some other  !");
                        continue;
                    }
                }
                if ((arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2] && (arr[0][0] != ' ')) ||
                        (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && (arr[0][0] != ' ')) ||
                        (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0] && (arr[0][0] != ' ')) ||
                        (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1] && (arr[0][1] != ' ')) ||
                        (arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2] && (arr[0][2] != ' ')) ||
                        (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0] && (arr[0][2] != ' ')) ||
                        (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2] && (arr[1][0] != ' ')) ||
                        (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2] && (arr[2][0] != ' '))) {
                    System.out.println("\n----------Player 1 wins the game !----------");
                    break;
                }
                currentplayer = 2;
            } else {
                System.out.println("\n----------Player 2's Turn----------\n");
                while (true) {
                    System.out.print("Enter the place where you want to insert O : (1-9) : ");
                    int p = sc.nextInt();
                    if (!(p >= 1 || p <= 9)) {
                        System.out.println("\nWrong input given ! please try again");
                        continue;
                    }

                    int x, y;
                    y = (p - 1) / 3;
                    x = (p - 1) % 3;
                    if (arr[y][x] == ' ') {
                        arr[y][x] = 'O';
                        break;
                    } else {
                        System.out.println("\nThis place is already filled - please try some other  !");
                        continue;
                    }
                }
                if ((arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2] && (arr[0][0] != ' ')) ||
                        (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && (arr[0][0] != ' ')) ||
                        (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0] && (arr[0][0] != ' ')) ||
                        (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1] && (arr[0][1] != ' ')) ||
                        (arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2] && (arr[0][2] != ' ')) ||
                        (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0] && (arr[0][2] != ' ')) ||
                        (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2] && (arr[1][0] != ' ')) ||
                        (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2] && (arr[2][0] != ' '))) {
                    System.out.println("\n----------Player 2 wins the game !----------");
                    break;
                }
                currentplayer = 1;
            }
            System.out.println("\n-------------");
            for (int i = 0; i < 3; i++) {
                System.out.print("| ");
                for (int j = 0; j < 3; j++) {
                    System.out.print(arr[i][j]);
                    System.out.print(" | ");
                }
                System.out.println("\n-------------");
            }
        }
        System.out.println("\n-------------");
        for (int i = 0; i < 3; i++) {
            System.out.print("| ");
            for (int j = 0; j < 3; j++) {
                System.out.print(arr[i][j]);
                System.out.print(" | ");
            }
            System.out.println("\n-------------");
        }
        sc.close();
    }
}
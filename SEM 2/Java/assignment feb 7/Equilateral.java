import java.util.Scanner;

public class Equilateral {
    private static Scanner sc;

    public static void main(String[] args) {

        double side1, side2, side3;
        sc = new Scanner(System.in);

        System.out.println("Please Enter Three sides of Triangle ");
        side1 = sc.nextDouble();
        side2 = sc.nextDouble();
        side3 = sc.nextDouble();

        if (side1 <= 0 || side2 <= 0 || side3 <= 0)
            System.out.println("Invalid side length");

        else if (side1 == side2 && side2 == side3)
            System.out.println("It is an Equilateral Triangle");
        else
            System.out.println("Triangle is not equilateral");
    }
}
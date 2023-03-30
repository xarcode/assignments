public class TriangleChecker {
    public static void main(String[] args) {
        int angle1 = 60, angle2 = 60, angle3 = 60;
        if(angle1 + angle2 + angle3 != 180){
            System.out.println("Not a triangle");
            return;
        }
        if(angle1 == angle2 && angle2 == angle3 && angle3 == 60) System.out.println("Equilateral Triangle");
        else if(angle1 == 90 || angle2 == 90 || angle3 == 90)
            System.out.println("Right Angled Triangle");
        else if(angle1 == angle2 || angle2 == angle3 || angle3 == angle1) System.out.println("Isosceles Triangle");
    }
}

import java.util.*;

public class Ques7 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("\nEnter the coordinates of the triangular pyramid: ");
        System.out.print("x1 y1 z1: ");
        double x1 = sc.nextDouble(), y1 = sc.nextDouble(), z1 = sc.nextDouble();
        System.out.print("x2 y2 z2: ");
        double x2 = sc.nextDouble(), y2 = sc.nextDouble(), z2 = sc.nextDouble();
        System.out.print("x3 y3 z3: ");
        double x3 = sc.nextDouble(), y3 = sc.nextDouble(), z3 = sc.nextDouble();
        System.out.print("x4 y4 z4: ");
        double x4 = sc.nextDouble(), y4 = sc.nextDouble(), z4 = sc.nextDouble();
        Point p1 = new Point(x1, y1, z1), p2 = new Point(x2, y2, z2), p3 = new Point(x3, y3, z3),
                p4 = new Point(x4, y4, z4);
        Triangle T1 = new Triangle(p1, p2, p3),
                T2 = new Triangle(p1, p2, p4),
                T3 = new Triangle(p1, p4, p3),
                Base = new Triangle(p2, p4, p3);
        TriangularPyramid TP = new TriangularPyramid(T1, T2, T3, Base);
        // System.out.println(T1.getType());
        // // System.out.println(T2.getType());
        // // System.out.println(T3.getType());
        // // System.out.println(Base.getType());
        System.out.println("\nType of Pyramid: " + TP.getType());
        sc.close();
    }
}

enum TypeOfTriangularPyramid {
    NOTTETRAHEDRON, TETRAHEDRON
};

enum TypeOfTriangle {
    EQUILATERAL, SCALENE, ISOSCELES;
};

class Point {
    private double x, y, z;

    Point() {
        this.x = this.y = this.z = 0;
    }

    Point(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    Point(Point P) {
        this(P.x, P.y, P.z);
    }

    double retX() {
        return x;
    }

    double retY() {
        return y;
    }

    double retZ() {
        return z;
    }
}

class Triangle {
    private Point p1, p2, p3;
    private double s1, s2, s3;
    private TypeOfTriangle type;
    private Point Centroid = new Point();

    Triangle() {
        this.p1 = new Point();
        this.p2 = new Point();
        this.p3 = new Point();
        setType();
    }

    Triangle(Point p1, Point p2, Point p3) {
        this.p1 = new Point(p1);
        this.p2 = new Point(p2);
        this.p3 = new Point(p3);
        this.s1 = getDist(p1, p2);
        this.s2 = getDist(p2, p3);
        this.s3 = getDist(p3, p1);
        Centroid = new Point();
        setCentroid();
        setType();
    }

    Triangle(Triangle T) {
        this(T.p1, T.p2, T.p3);
        setType();
    }

    double getDist(Point p1, Point p2) {
        return Math.sqrt(Math.pow(p1.retX() - p2.retX(), 2) + Math.pow(p1.retY() - p2.retY(), 2)
                + Math.pow(p1.retZ() - p2.retZ(), 2));
    }

    void setType() {
        if (s1 == s2 && s2 == s3)
            this.type = TypeOfTriangle.EQUILATERAL;
        else if ((s1 == s2) || (s2 == s3) || (s3 == s1))
            this.type = TypeOfTriangle.ISOSCELES;
        else
            this.type = TypeOfTriangle.SCALENE;
    }

    void setCentroid() {
        Centroid = new Point(((p1.retX() + p2.retX() + p3.retX()) / 3),
                ((p1.retY() + p2.retY() + p3.retY()) / 3),
                ((p1.retY() + p2.retY() + p3.retY()) / 3));
    }

    Point getCentroid() {
        return Centroid;
    }

    TypeOfTriangle getType() {
        return type;
    }
}

class TriangularPyramid {
    private Triangle T1;
    private Triangle T2;
    private Triangle T3;
    private Triangle Base;
    private Point Centroid;
    private TypeOfTriangularPyramid type;

    TriangularPyramid(Triangle T1, Triangle T2, Triangle T3, Triangle Base) {
        this.T1 = new Triangle(T1);
        this.T2 = new Triangle(T2);
        this.T3 = new Triangle(T3);
        this.Base = new Triangle(Base);
        setType();
        setCentroid();
    }

    void setType() {
        if (this.Base.getType() == TypeOfTriangle.EQUILATERAL &&
                this.T1.getType() == TypeOfTriangle.EQUILATERAL &&
                this.T2.getType() == TypeOfTriangle.EQUILATERAL &&
                this.T3.getType() == TypeOfTriangle.EQUILATERAL) {
            this.type = TypeOfTriangularPyramid.TETRAHEDRON;
        } else
            this.type = TypeOfTriangularPyramid.NOTTETRAHEDRON;
    }

    void setCentroid() {
        Point BaseCentroid = new Point(this.Base.getCentroid()),
                T1Centroid = T1.getCentroid(),
                T2Centroid = T2.getCentroid(),
                T3Centroid = T3.getCentroid();
        Centroid = new Point(
                ((BaseCentroid.retX() + T1Centroid.retX() + T2Centroid.retX() + T3Centroid.retX()) / 4),
                ((BaseCentroid.retY() + T1Centroid.retY() + T2Centroid.retY() + T3Centroid.retY()) / 4),
                ((BaseCentroid.retZ() + T1Centroid.retZ() + T2Centroid.retZ() + T3Centroid.retZ()) / 4));
    }

    TypeOfTriangularPyramid getType() {
        return type;
    }

    Point getCentroid() {
        return Centroid;
    }
}
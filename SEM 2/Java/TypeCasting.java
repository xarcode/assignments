public class TypeCasting {
    public static void main(String[] args) {
        // widening casting
        double double1 = 76.66d;
        float float1 = 89.9f;
        long long1 = 123;
        int int1 = 75;
        char char1 = 'a';
        short short1 = 67;
        byte byte1 = 0;
        
        short short2 = byte1;    // byte -> short
        int int2 = char1;        // char -> int
        long long2 = int1;       // int -> long
        float float2 = long1;    // long -> float
        double double2 = float1; // float -> double

        System.out.println(short2);
        System.out.println(int2);
        System.out.println(long2);
        System.out.println(float2);
        System.out.println(double2);
        
        // narrowing casting
        float2 = (float)double1;   // double -> float
        long2 = (long)float1;      // float -> long
        int2 = (int)long1;         // long -> int
        char char2 = (char)int1;   // int -> char
        short2 = (short)char1;     // char -> short
        byte byte2 = (byte)short1; // short -> byte
        
        System.out.println(byte2);
        System.out.println(short2);
        System.out.println(char2);
        System.out.println(int2);
        System.out.println(long2);
        System.out.println(float2);
        System.out.println(double2);
    }
}
 
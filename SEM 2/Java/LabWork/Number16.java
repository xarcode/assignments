public class Number16 {
    public static void main(String[] args) {
        boolean x = true;

        {
            bl2:{
                {
                    System.out.println("Block 3");
                    if(x) break bl2;
                }
                System.out.println("Block 2");
            }
            System.out.println("Blcok 1");
        }
        System.out.println("out of all blocks");
    }
}

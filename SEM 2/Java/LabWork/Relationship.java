class Main {
    public static void main(String args[]) {
        Relationship r = new Relationship();
        r.showGrandChild("Jim");
        r.showGrandParent("John");
    }
}

class Relationship {
    private String gp[];
    private String gc[];
    private int count[];

    public Relationship() {
        gp = new String[4];
        gp[0] = "Tim";
        gp[1] = "Jim";
        gp[2] = "Kim";
        gp[3] = "Karen";

        gc = new String[6];
        gc[0] = "Karla";
        gc[1] = "Bobby";
        gc[2] = "Grey";
        gc[3] = "Paul";
        gc[4] = "Peter";
        gc[5] = "John";

        count = new int[4];
        count[0] = 2;
        count[1] = 1;
        count[2] = 1;
        count[3] = 2;
    }

    public void showGrandChild(String s) {
        int idx = -1;
        for (int i = 0; i < 4; i++) {
            if (gp[i].equals(s)) {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            System.out.println(s + " does not exist");
            return;
        }

        int sum = 0;
        int noOfGrandChildren = count[idx];

        int i = 0;
        while (i < idx) {
            sum += count[i++];
        }

        i = sum;
        while (noOfGrandChildren != 0) {
            System.out.println(gc[i++]);
            noOfGrandChildren--;
        }
    }

    public void showGrandParent(String s){
        int idx = -1;
        for(int i = 0; i < 6; i++){
            if(gc[i].equals(s)){
                idx = i;
                break;
            }
        }

        if(idx == -1){
            System.out.println(s + " does not exist");
            return;
        }

        int sum = 0;
        int i = 0;
        while(sum <= idx){
            sum += count[i++];
        }

        i--;
        System.out.println(gp[i]);
    }
}
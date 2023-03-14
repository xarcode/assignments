/**
 * MinDistance
 */
public class MinDistance {

    public static void main(String[] args) {
        int arr[] = {4, 8, 6, 1, 2, 9};
        int dist = 99999, minIdx = -1;

        for(int i = 1; i < 6; i++){
            if(dist > Math.abs(arr[i] - arr[i - 1])){
                dist = Math.abs(arr[i] - arr[i - 1]);
                minIdx = i - 1;
            }
        }
        
        System.out.println(minIdx);
    }
}
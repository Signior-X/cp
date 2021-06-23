// Advanced Binary searching, as it can be used in many ways

import java.util.Scanner;

class wood {

    public static boolean isSufficient(int [] ar, int h, int m) {
        // check for if sufficient

        int sum = 0;
        for (int val : ar) {
            sum += ((val - h) > 0 ? (val- h) : 0);

            if (sum >= m) return true;
        }

        return false;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m;
        n = sc.nextInt(); m = sc.nextInt();

        int ar[] = new int[n];
        for(int i=0; i<n; i++) {
            ar[i] = sc.nextInt();
        }

        // T T T T F F F F
        int low = 0, high = 1000;
        while(low < high) {
            System.out.println(low + " " + high);
            int mid = low + (high - low) / 2;

            if (isSufficient(ar, mid, m)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        System.out.println(isSufficient(ar, low-1, m) + "\t" + isSufficient(ar, low, m) + "\t" + isSufficient(ar, high, m));

        sc.close();
    }
}
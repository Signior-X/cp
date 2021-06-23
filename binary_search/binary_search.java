import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

class binary_search {

    public static int lower_bound(int[] ar, int key) {
        int low = 0, high = ar.length;

        while ( low < high ) {
            int mid = low + (high - low) / 2;

            // Helps in finding weather to take the left most or right most
            if (ar[mid] < key) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }

    public static int upper_bound(int[] ar, int key) {
        int low = 0, high = ar.length - 1;

        while ( low < high ) {
            int mid = low + (high - low) / 2;

            // Helps in finding weather to take the left most or right most
            if (ar[mid] <= key) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        if (low < ar.length && ar[low] <= key) {
            low++;
        }

        // In this case we check for low - 1 as this gives 1 more than the required always
        if (low > 0 && ar[low - 1] == key) return low - 1;


        return low;
    }

    public static int doBinarySearch(int[] ar, int key) {
        int low = 0, high = ar.length - 1;

        while ( low < high ) {
            int mid = low + (high - low) / 2;

            // Helps in finding weather to take the left most or right most
            if (ar[mid] < key) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        if (ar[low] == key) return low;

        return -1;
    }

    public static int doRightBinarySearch(int[] ar, int key) {
        int low = 0, high = ar.length - 1;

        while ( low < high ) {
            int mid = low + (high - low) / 2;

            // Helps in finding weather to take the left most or right most
            if (ar[mid] <= key) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        // If last element
        if (low < ar.length && ar[low] <= key) {
            low++;
        }

        // In this case we check for low - 1 as this gives 1 more than the required always
        if (low > 0 && ar[low - 1] == key) return low - 1;

        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int key;

        // int key = sc.nextInt();

        int ar[] = {3, 5, 5, 5, 5, 7, 9, 10, 10, 10};

        for (int i=0; i < ar[ar.length - 1] + 2 ; i++) {
            key = i;

            System.out.println(key + "\t" + lower_bound(ar, key) + "\t" + upper_bound(ar, key) + "\t" + doBinarySearch(ar, key) + "\t" + doRightBinarySearch(ar, key));
    
        }

        sc.close();
    }
}
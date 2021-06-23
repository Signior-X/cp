class bisect {

    // bisect_left and bisect_right gives different answers if a key is present
    
    public static int bisect_left(int ar[], int low, int high, int key) {

        while(low < high) {
            int mid = low + (high - low) / 2;

            if (ar[mid] < key) low = mid + 1;
            else high = mid;
        }

        // Take care of smaller than sign
        if (low < ar.length && ar[low] < key) low++;

        return low;
    }

    public static int bisect_right(int ar[], int low, int high, int key) {

        while(low < high) {
            int mid = low + (high - low) / 2;

            if (ar[mid] <= key) low = mid + 1;
            else high = mid;
        }

        if (low < ar.length && ar[low] <= key) low++;

        return low;
    }

    public static void main(String args[]) {
        int ar[] = {1, 3, 4, 4, 4, 7, 8};

        for(int i = 0; i<12; i++) {
            System.out.println(i + " left " + bisect_left(ar, 0, ar.length - 1, i) + " right " + bisect_right(ar, 0, ar.length - 1, i));
        }
    }
}
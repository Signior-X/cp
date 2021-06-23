// DP for choicing like questions

class maximum_sum_subarray {

    public static void printArr(int[] arr) {
        for(int val : arr) System.out.print(val + " ");
        System.out.println();
    }

    public static int[] solve(int[] arr) {
        printArr(arr);

        int result = arr[0];
        int max_till_now = arr[0];
        int where_it_is[] = {0, 0};

        for(int i=1; i<arr.length; i++) {
            // Make a choice to continue the subarray or start a new one
            if (max_till_now + arr[i] >= arr[i]) {
                // Continue previous one
                max_till_now = max_till_now + arr[i];
                where_it_is[1] = i;
            } else {
                // Start a new one
                where_it_is[0] = i; where_it_is[1] = i;
                max_till_now = arr[i];
            }

            result = Math.max(result, max_till_now);
        }

        int ans[] = { result, where_it_is[0], where_it_is[1] };
        printArr((ans));

        return ans;
    }

    public static void main(String[] args) {
        int arr[] = { 1, 2, -2, 4, 2, -5, 1 };
        solve(arr);
    }
}
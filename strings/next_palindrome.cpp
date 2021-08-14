string solve(string A) {
    int n = A.length();
    bool flagt = false;
    bool odd = n & 1;
    bool isP = true;

    if (A == "9") return "11";

    int i = 1 + (n - 1) / 2;
    int st = i;
    while(i < n) {
        int mrr = n - i - 1;

        if (!flagt) {

            if (A[i] == A[mrr]) {
                i++;
                continue;
            } else if (A[i] < A[mrr]) {
                A[i] = A[mrr];
                flagt = true;
                isP = false;
            } else {

                if (A[i] != '9') {
                    A[i] = A[mrr];
                }

                // When you are not able to increase the value
                int j = st - 1;

                while(j >= 0 && A[j] == '9') {
                    A[j] = '0';
                    A[n - j - 1] = '0';
                    j--;
                }

                // now the left one has to be incremented by 1
                if (j < 0) {
                    // 9
                    A = '1' + A;
                } else {
                    A[j]++;
                    A[n - j - 1] = A[j];
                }

                flagt = true;
                isP = false;
            }

        } else {
            // Has already become greater
            A[i] = A[mrr];
            isP = false;
        }

        i++;
    }

    if (isP) {

        int j = st - 1;

        while(j >= 0 && A[j] == '9') {
            A[j] = '0';
                A[n - j - 1] = '0';
                j--;
        }

        // now the left one has to be incremented by 1
        if (j < 0) {
            // 9
            A = '1' + A;
            int tl = A.length();
            A[tl - 1] = '1';
        } else {
            A[j]++;
            A[n - j - 1] = A[j];
        }

    }

    return A;

}
#include <bits/stdc++.h>

using namespace std;

double solve(const vector<int> &X, const vector<int> &Y) {
    // X is the smaller one
    // Tushar roy video
    // we partition the smaller array in such a way
    // That we get the condition / critical point

    double med = 0.0;

    // Now we are going to think of partitioning
    int start = 0;
    int end = X.size();

    while(start <= end) {

        // check for the condition
        int partX = (start + end) / 2;
        int partY = (X.size() + Y.size() + 1) / 2 - partX;

        int xl, xr, yl, yr;

        xl = (partX > 0) ? X[partX - 1] : INT_MIN;
        xr = (partX < X.size()) ? X[partX] : INT_MAX; 

        yl = Y[partY - 1];
        yr = Y[partY];

        if (yr >= xl && xr >= yl) {

            if ((X.size() + Y.size()) & 1) {
                med = max(xl, yl);
            } else {
                med = (max(xl, yl) + min(xr, yr)) / 2.0;
            }

            return med;

        } else if (yl > xr) {
            start = partX + 1;
        } else {
            end = partX - 1;
        }

    }

    return med;
}

double findMedianSortedArrays(const vector<int> &X, const vector<int> &Y) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    // We are going to take smaller as X and bigger as Y
    
    int al = X.size();
    int bl = Y.size();

    if (X.size() <= Y.size()) {
        return solve(X, Y);
    } else {
        return solve(Y, X);
    }

}

int main () {
    vector<int> v1 = {1, 4};
    vector<int> v2 = {2, 3};
    cout << findMedianSortedArrays(v1, v2) << "\n";
}

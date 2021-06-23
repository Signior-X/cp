#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define print(val) cout << val << "\n"

int main() {

    int t = 1;
    while(t-- > 0) {
        int ar[] = {1, 2, 3, 4, 2, -1};
        int n = sizeof(ar)/sizeof(ar[0]);

        int prefix_sum[n];
        prefix_sum[0] = ar[0];
        for (int i=1; i<n; i++) {
            prefix_sum[i] = prefix_sum[i-1] + ar[i];
        }

        for (int val : prefix_sum) {
            cout << val << " ";
        }

        cout << "\n";
    }

    return 0;
}
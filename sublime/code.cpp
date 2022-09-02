#include <bits/stdc++.h>
using namespace std;

int bnexp(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    int ans = bnexp(5, 2);
    cout << ans << "\n";

    int t;
    cin >> t;
    while(t-- > 0) {
        cout << t << "\n";
    }

	return 0;
}
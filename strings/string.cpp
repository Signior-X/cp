#include <bits/stdc++.h>
using namespace std;

int main () {

    int n;
    cin >> n;

    int ar[n] = {-1, -1};

    for (auto &val : ar) {
        cout << val << " ";
    }

    cout << "\n";

    vector<int> ans(n);
    ans[2] = 1;

    for(auto &val : ans) {
        cout << val << " ";
    }

    cout << "\n";

    return 0;
}
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define test int T; cin >> T; while(T--)
#define printv(ele) for(auto vl : ele) cout << vl << " "; cout << "\n";

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>

int cnt = 0;

void lsort(vector<int> &A, int i, int j) {

    // cout << i << " " << j << "\n";
    // cout << cnt << "\n";

    if (A[i] > A[j]) swap(A[i], A[j]);

    if (i + 1 >= j) return;

    cnt++;

    int k = (j - i + 1) / 3;

    lsort(A, i, j - k);
    lsort(A, i + k, j);
    lsort(A, i, j - k);
}

void solve() {
    int n;
    cin >> n;

    vector<int> A(n);

    lsort(A, 0, A.size() - 1);

    cout << n << " " << cnt << "\n";
    printv(A);
    cout << "\n";
}

int main() {
    // you can write to stdout for debugging purposes, e.g.
    // std::cout << "This is a debug message" << std::endl;

    test solve();

}

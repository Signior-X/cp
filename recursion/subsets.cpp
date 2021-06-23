#include <bits/stdc++.h>
using namespace std;

// O(2^n)
void solve(vector<int> &curr, int *ar, int checking_for, int n, vector<vector<int>> &ans) {
    if (checking_for == n) {
        ans.push_back(curr);
        return;
    }

    // Now first move without adding curr
    solve(curr, ar, checking_for + 1, n, ans);

    curr.push_back(ar[checking_for]);
    solve(curr, ar, checking_for + 1, n, ans);
    curr.pop_back();

    return;
}

int main () {
    // Find all the subsets of an array
    int ar[] = {3, 5, 7, 8, 9, 10, 12, 15, 16, 18, 19, 20, 21, 23, 45};

    // There will be 2 ^ n subsets
    // we will be using recursion and backtracking to solve this problem
    vector<int> vecs = {};
    vector<vector<int>> ans;

    solve(vecs, ar, 0, sizeof(ar)/ sizeof(ar[0]), ans);

    for (auto &val : ans) {
        for (auto &val2 : val) {
            cout << val2 << " ";
        }

        cout << "\n";
    }

}
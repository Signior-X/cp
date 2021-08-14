#include <bits/stdc++.h>
using namespace std;

#define test int T; cin >> T; while(T--)
#define printv(ele) for(auto &vl : ele) cout << vl << " "; cout << "\n";

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>

int log2F(int v) {
    return 32 - __builtin_clz(v) - 1;
}

void build(vvi &sparse, vi &v) {
    int n = v.size();

    for(int i = 0; i < n; i++) {
        sparse[i][0] = v[i];
    }

    for(int j = 1; (1 << j) <= n; j++) {
        for(int i = 0; i + (1 << j) <= n; i++) {
            sparse[i][j] = sparse[i][j - 1] & sparse[i + (1 << (j - 1))][j - 1];
        }
    }
}

int find_sum(vvi &sparse, int l, int r) {
    int j = log2F(r - l + 1);

    return sparse[l][j] & sparse[r - (1 << j) + 1][j];
}


int main() {
    vi v = {1, 2, 3, 4, 5, 6, 7, 8};

    int n = v.size();

    int mxl = log2F(n) + 2;
    vvi sparse(n, vi(mxl, 0));

    build(sparse, v);

    for(vi &edge : sparse) { printv(edge) };

    cout << find_sum(sparse, 2, 5) << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define test int T; cin >> T; while(T--)
#define printv(ele) for(auto &vl : ele) cout << vl << " "; cout << "\n";

void build(vvi &sparse, vi &ar) {
	int n = ar.size();

	for(int i = 0; i < n; i++) {
		sparse[i][0] = ar[i];
	}

	for(int j = 1; (1 << j) <= n; j++) {
		for(int i = 0; i + (1 << j) <= n; i++ ) {
			sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(vvi &sparse, int l, int r) {
	int j = (int)log2(r - l + 1);
	
	return min(sparse[l][j], sparse[r - (1 << j) + 1][j]);
}

void solve() {

	int n;
	cin >> n;
	vi ar(n);

	for(int i = 0; i < n; i++) cin >> ar[i];

	int maxl = log2(n) + 1;
	vvi sparse(n, vi(maxl, -1));
	build(sparse, ar);

	for(int i = 0; i < n; i++) {
		printv(sparse[i]);
	}

	cout << query(sparse, 0, 4) << endl;
    cout << query(sparse, 4, 7) << endl;
    cout << query(sparse, 7, 8) << endl;
}

int main () {

	test solve();
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> seg;

void build(vector<ll> v, int ind, int low, int high) {
	if (low == high) {
		seg[ind] = v[low];
		return;
	}

	int md = low + (high - low) / 2;
	build(v, 2 * ind + 1, low, md);
	build(v, 2 * ind + 2, md + 1, high);

	seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

ll range_query(int ind, int low, int high, int l, int r) {
	if (low >= l && high <= r) return seg[ind];
	if (high < l || low > r) return INT_MIN;

	int md = low + (high - low) / 2;
	int lft = range_query(2 * ind + 1, low, md, l, r);
	int rht = range_query(2 * ind + 2, md + 1, high, l, r);

	return max(lft, rht);
}

int main () {
	vector<ll> v = {1, 2, 5, 7, 3, 5, 9};

	int n = v.size();
	int segSize = pow(2, log2(n) + 1) + 1;
	seg.resize(segSize, INT_MIN);

	build(v, 0, 0, n - 1);

	for(ll &vl : seg) cout << vl << "\n";
	cout << "\n\n";
	
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			cout << i << " " << j << " " << range_query(0, 0, n - 1, i, j) << "\n";
		}
	}

	return 0;
}
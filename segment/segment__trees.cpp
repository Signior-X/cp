#include <bits/stdc++.h>
using namespace std;

#define ll long long


vector<int> seg(200005, INT_MAX);

// Index store the tree in linear form
void build(vector<int> &v, int ind, int low, int high) {
	// cout << ind << " " << low << " " << high << "\n";
	if (low == high) {
		seg[ind] = v[low];
		return;
	}

	int md = low + (high - low) / 2;
	build(v, 2 * ind + 1, low, md);
	build(v, 2 * ind + 2, md + 1, high);

	seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}


int range_query(int ind, int low, int high, int l, int r) {
	if (low >= l && high <=r) return seg[ind];
	if (high < l || low > r) return INT_MAX;

	int md = low + (high - low) / 2;

	ll left = range_query(2 * ind + 1, low, md, l, r);
	ll right = range_query(2 * ind + 2, md + 1, high, l, r);
	return min(left, right);
}


int main() {

	vector<int> v = {7, 3, 4, 0, 2, 1, 8, 10, 11, 12, 13, 14, 15, 16, 16, 18};

	// How to create segment tree
	int n = v.size();
	build(v, 0, 0, n - 1);

	int cnt = 0;
	for(int i = 0; i < pow(2, log2(n) + 1); i++) {
		cnt++; cout << seg[i] << "\n";
	}

	// cout << "\n" << range_query(0, 0, n - 1, 6, 7) << "\n";

	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			cout << i << " " << j << " " << range_query(0, 0, n - 2, i, j) << "\n";
		}
	}

	return 0;
}


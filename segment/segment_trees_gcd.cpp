#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void build(vector<long> &seg, vector<long> &v, int ind, int low, int high) {
	if (low == high) {
		seg[ind] = v[low];
		return;
	}

	int md = low + (high - low) / 2;
	build(seg, v, 2 * ind + 1, low, md);
	build(seg, v, 2 * ind + 2, md + 1, high);

	seg[ind] = gcd(seg[2 * ind + 1], seg[2 * ind + 2]);
}

ll range_query(vector<long> &seg, int ind, int low, int high, int l, int r) {
	if (low >= l && high <= r) return seg[ind];
	if (high < l || low > r) return 0;

	int md = low + (high - low) / 2;
	int lft = range_query(seg, 2 * ind + 1, low, md, l, r);
	int rht = range_query(seg, 2 * ind + 2, md + 1, high, l, r);

	return gcd(lft, rht);
}

int main () {

	vector<long> v = {10, 35, 25, 27, 18, 10, 15};
	int n = v.size();
	int treeNodes = pow(2, log2(n) + 1);

	vector<long> seg(treeNodes, 0);
	build(seg, v, 0, 0, n - 1);

	for(long &vl : seg) {
		cout << vl << "\n";
	}

	cout << range_query(seg, 0, 0, n - 1, 0, 2);

	return 0;
}
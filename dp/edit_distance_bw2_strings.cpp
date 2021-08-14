#include <bits/stdc++.h>
using namespace std;

int find_min(string &s1, string &s2, int a, int b, vector<vector<int>> &mem) {
	// Taking 0 for empty string
	// We a and b as counts of numbers of characters
	if (a == 0) return b;
	if (b == 0) return a;

	if (mem[a-1][b-1] != -1) {
		// Already computed
		return mem[a-1][b-1];
	}

	if (s1[a-1] == s2[b-1]) {
		// Replace function
		return find_min(s1, s2, a - 1, b - 1, mem);
	}

	// They are not equal
	// Find the minimum
	int m1 = find_min(s1, s2, a - 1, b, mem);
	int m2 = find_min(s1, s2, a - 1, b - 1, mem);
	int m3 = find_min(s1, s2, a, b - 1, mem);

	m2 = min(m1, m2);
	m3 = min(m2, m3);

	mem[a-1][b-1] = 1 + m3;

	return 1 + m3;
}

int main () {

	// Insert, replace or delete
	// How many operations to actually make them equal

	string s1 = "properties";
	string s2 = "prosperity";

	vector<vector<int>> mem(s1.length(), vector<int>(s2.length(), -1));
	int ans = find_min(s1, s2, s1.length(), s2.length(), mem);
	cout << ans << "\n";

}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

int main() {

	// we will print subsets using bitmasking
	vector<int> v = {1, 2, 3, 4, 5};

	int n = v.size();
	for(int i = 0; i < (1 << n); i++) {
		bitset<32> bset(i);

		for(int i = 0; i < n; i++) {
			if (bset[i]) cout << v[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}
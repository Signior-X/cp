#include <bits/stdc++.h>

using namespace std;

int main () {

	vector<int> ar = {8, 7, 4, 6, 4, 7, 9, 4};

	// Find all the indices of the least value in this vector
	// IN a single loop
	int mn = INT_MAX;
	vector<int> ans;

	for(int i = 0; i < ar.size(); i++) {
		int val = ar[i];
		if (mn > val) {
			mn = val;
			ans = {i};
		} else if(mn == val) {
			ans.push_back(i);
		}
	}

	for(auto &val : ans) {
		cout << val << " ";
	}

	cout << "\n";

	return 0;
}
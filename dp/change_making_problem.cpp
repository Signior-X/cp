#include <bits/stdc++.h>

using namespace std;

// written in multiple steps
// 1st only with int
// 2nd with pair<int, bool>
// 3rd with pair<pair<int, bool>, vector<int>>

pair<pair<int, bool>, vector<int>> find(int toMake, vector<int> &coins, unordered_map<int, pair<pair<int, bool>, vector<int>>> &mem) {
	// Go for a top down and returning the best answer
	// similar to bottom up
	// Give the answer for the minimum needed
	if (toMake < 0) return {{INT_MAX, false}, {}};

	if (toMake == 0) return {{0, true}, {}};

	if (mem.find(toMake) != mem.end()) {
		// Already computed
		return mem[toMake];
	}

	int mn = INT_MAX;
	int mnv = -1;
	bool bl = false;
	vector<int> current;

	for (int &val : coins) {
		pair<pair<int, bool>, vector<int>> gt = find(toMake - val, coins, mem);

		// find the minimum true
		if (gt.first.second == true) {
			bl = true;

			if (gt.first.first < mn) {
				mn = gt.first.first;
				current = gt.second;
				mnv = val;
			}
		}
	}

	if (mnv != -1) {
		current.push_back(mnv);
	}

	mem[toMake] = {{1 + mn, bl}, current};

	return {{1 + mn, bl}, current};
}


pair<pair<int, bool>, vector<int>> find_using_dp(int toMake, vector<int> &coins) {
	// To make 
	//   0 1 2 3 4 5 6 7 8
	// TODO


	// Using a single array, this will be a simple bottom up

}


int main() {
	
	// Fewest coins to make the change ??

	int toMake = 18;
	vector<int> coins = {1, 5, 2};
	unordered_map<int, pair<pair<int, bool>, vector<int>>> mem(toMake);

	pair<pair<int, bool>, vector<int>> ans = find(toMake, coins, mem);

	cout << ans.first.first << " " << ans.first.second << "\n";

	for(auto &val : ans.second) {
		cout << val << " ";
	}

	cout << "\n";

	return 0;
}


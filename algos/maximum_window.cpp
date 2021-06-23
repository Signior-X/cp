#include <bits/stdc++.h>
using namespace std;

// O(n * log(n))
// Better can be done using dequeu
// check dequeue one 

int main() {

	vector<int> nums = {1, 3, 1, 2, 0, 5};
	int k = 4;

	// So first do some precomputations for 0 to k-1
	multiset<int> mp; // index, max_value

	vector<int> ans(nums.size() - k + 1);

	for(int i = 0; i < k; i++) {
		mp.insert(-1*nums[i]);
	}

	auto it = mp.begin();
	cout << *it << "\n";
	ans[0] = (*it) * -1;

	// Now we will be shfiting the windows
	for(int i = 1; i + k - 1 < nums.size(); i++) {
		// we are trying to insert i in our block
		int j = i + k - 1;

		// write code here
		it = mp.find(-1*nums[i-1]);
		mp.erase(it);

		mp.insert(-1*nums[j]);

		it = mp.begin();
		ans[i] = (*it) * -1;
	}

	for(auto &vl : ans) {
		cout << vl << " ";
	}

	cout << "\n";

	return 0;
}
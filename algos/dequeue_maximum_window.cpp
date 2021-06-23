#include <bits/stdc++.h>
using namespace std;

int main() {

	vector<int> nums = {1, 3, 1, 2, 0, 5};
	int k = 4;

	vector<int> ans(nums.size() - k + 1);

	// deque for storing the indices
	deque<int> dq;
	dq.push_back(0);

	for(int i = 1; i < k; i++) {
		while(!dq.empty() && nums[dq.back()] < nums[i]) {
			dq.pop_back();
		}

		dq.push_back(i);
	}

	ans[0] = nums[dq.front()];

	// Now we will be shfiting the windows
	for(int i = 1; i + k - 1 < nums.size(); i++) {
		// we are trying to insert i in our block
		int j = i + k - 1;

		// write code here
		if (dq.front() < i) {
			dq.pop_front();
		}

		while(!dq.empty() && nums[dq.back()] < nums[j]) {
			dq.pop_back();
		}

		dq.push_back(j);

		// for(auto &val : dq) { cout << val << " "; } cout << " dq \n";
		
		ans[i] = nums[dq.front()];
	}

	for(auto &vl : ans) {
		cout << vl << " ";
	}

	cout << "\n";

	return 0;
}
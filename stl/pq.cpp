// Try making a priority queue with custom coparator functions
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

#define printv(ele) for(auto &vlu : ele) cout << vlu << " "; cout << "\n";
#define printp(ele) for(auto &vlu : ele) cout << vlu.first << " " << vlu.second << "\n";
#define pii pair<int, int>

int main () {

	auto cmp = [](const pii &a, const pii &b) {
		if (a.first > b.first)
			return false;
		else if (a.first < b.first)
			return true;
		else {
			if (a.second > b.second)
				return true;
			else
				return false;
		}
	};

	multiset<pii, decltype(cmp)> pq(cmp);

	pq.insert({5, 8});
	pq.insert({1, 1});
	pq.insert({5, 4});
	pq.insert({5, 9});
	pq.insert({3, 4});
	pq.insert({3, 8});
	pq.insert({6, 8});
	
	printp(pq);

	return 0;
}

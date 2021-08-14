#include <bits/stdc++.h>
using namespace std;

#define test int T; cin >> T; while(T--)
#define printv(ele) for(auto &vl : ele) cout << vl << " "; cout << "\n";

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>

vvi graph;
vi visited;

void dfs(int curr) {
	visited[curr] = true;

	cout << curr << "\n";

	for(int &vl : graph[curr]) {
		if (!visited[vl]) dfs(vl);
	}
}

int main() {

	// Here we are goind to do a dfs
	// this will work for both connected and disconnected graph
	int n = 5;
	graph = {
		{1, 4},
		{2},
		{0, 3},
		{3},
		{2}
	};

	visited.resize(n, false);
	for(int i = 0; i < n; i++) {
		if (!visited[i]) dfs(i);
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define test int T; cin >> T; while(T--)
#define printv(ele) for(auto &vl : ele) cout << vl << " "; cout << "\n";

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>

vvi graph;
vi visited;

void bfs(int curr) {
	// Now starting from this current edge

	deque<int> q;
	visited[curr] = true;
	q.push_back(curr);

	while(q.size()) {
		int u = q.front();
		q.pop_front();

		cout << u << "\n";

		for(int &vl : graph[u]) {
			if (!visited[vl]) { 
				q.push_back(vl);
				visited[vl] = true;
			}
		}
	}
}

int main() {

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
		if (!visited[i]) bfs(i);
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

// BEST one Dijkstra using PQ

// Remember this Djikshtra algo appraoch
// For pairs and adjacency list approach

// Sample input

// 14 8 1
// 0 1 4
// 0 7 8
// 1 2 8
// 1 7 11
// 2 3 7
// 2 8 2
// 2 5 4
// 3 4 9
// 3 5 14
// 4 5 10
// 5 6 2
// 6 7 1
// 6 8 6
// 7 8 7


int main () {

	// First take input
	// n edges, m vertices, start point
	int n, m, start;
	cin >> n >> m >> start;
	int u, v, d;

	vector<int> pairs[n];
	for(int i = 0; i < n; i++) {
		cin >> u >> v >> d;
		pairs[i] = {u, v, d};
	}

	// O(E)
	vector<pair<int, int>> adjList[m];
	for(int i = 0; i < n; i++) {
		adjList[pairs[i][0]].push_back({pairs[i][1], pairs[i][2]});
	}

	vector<bool> visited(m, false);
	vector<int> minD(m, INT_MAX);
	minD[start] = 0;

	set<pair<int, int>> pq;
	pq.insert({0, start});

	while(!pq.empty()) {
		auto it = pq.begin();
		int ind = it -> second;
		int dist = it -> first;
		pq.erase(it);

		if (visited[ind]) continue;

		for(pair<int, int> v : adjList[ind]) {
			if (v.second + dist < minD[v.first]) {
				minD[v.first] = v.second + dist;

				pq.insert({minD[v.first], v.first});
			}
		}

		visited[ind] = true; 
	}

	for(int i = 0; i < m; i++) {
		cout << i << " " << minD[i] << "\n";
	}

	return 0;
}
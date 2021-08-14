#include <bits/stdc++.h>
using namespace std;

int findMinNode(vector<int> &minDistances, vector<int> &visited) {
	int minInd = -1;
	int minDist = INT_MAX;

	for(int i = 0; i < minDistances.size(); i++) {
		if (!visited[i] && minDistances[i] < minDist) {
			minInd = i;
			minDist = minDistances[i];
		}
	}

	return minInd;
}

vector<int> findShortestPath(vector<vector<int>> &graph, int start) {
	// O(n^2) for adjacency matrix
	
	int n = graph.size();
	vector<int> visited(n, false);
	vector<int> minDistances(n, INT_MAX);
	minDistances[start] = 0;

	for(int c = 0; c < n - 1; c++) {
		int minInd = findMinNode(minDistances, visited);

		for(int i = 0; i < n; i++) {
			if (!visited[i] && graph[minInd][i] != 0) {
				// Edge exists
				if(minDistances[minInd] + graph[minInd][i] < minDistances[i]) {
					minDistances[i] = minDistances[minInd] + graph[minInd][i];
				}
			}
		}

		visited[c] = true;
	}

	return minDistances;
}


vector<int> findShortestPathAdjList(vector<vector<pair<int, int>>> adjList, int start) {
	int n = adjList.size();

	vector<int> visited(n, false);
	vector<int> minDistances(n, INT_MAX);
	minDistances[start] = 0;

	set<pair<int, int>> pq;
	pq.insert({0, start});

	while(!pq.empty()) {
		auto it = pq.begin();
		int ind = it -> second;
		int dist = it -> first;
		// Finally remove from the priority queue
		pq.erase(it);

		cout << ind << "\n";


		if(!visited[ind]) {

			// Now loop the adjacency list
			for(pair<int, int> &v : adjList[ind]) {
					if (v.second + dist < minDistances[v.first]) {
						
						// Update the minDistances
						minDistances[v.first] = v.second + dist;

						// Also update in the PQ
						// Add only those which are not yet visited
						pq.insert({minDistances[v.first], v.first});
					}
			}
		}

		visited[ind] = true;
	}

	return minDistances;
}


int main() {

	// First create the graph adjacency list
	vector<vector<int>> graph = {
		{0, 1, 5, 0, 0, 0},
		{0, 0, 0, 0, 12, 15},
		{0, 0, 0, 4, 0, 0},
		{0, 2, 0, 0, 0, 3},
		{0, 0, 0, 0, 0, 2},
		{0, 0, 3, 0, 0, 0}
	};

	int start = 0;

	for(int &vl : findShortestPath(graph, start)) cout << vl << " ";
	cout << "\n";

	vector<vector<int>> edges = {
		{0, 1, 1},
		{0, 2, 5},
		{1, 4, 12},
		{1, 5, 15},
		{2, 3, 4},
		{3, 1, 2},
		{3, 5, 3},
		{4, 5, 2},
		{5, 2, 3}
	};

	vector<vector<pair<int, int>>> adjList(6);

	for(vector<int> &vl : edges) {
		adjList[vl[0]].push_back({vl[1], vl[2]});
	}

	for(int &vl : findShortestPathAdjList(adjList, start)) cout << vl << " ";
	cout << "\n";
	
	// for(int i = 0; i < adjList.size(); i++) {
	// 	for(int j = 0; j < adjList[i].size(); j++) {
	// 		cout << i << " " << adjList[i][j].first << " " << adjList[i][j].second << "\n";
	// 	}
//	// }

	return 0;
}

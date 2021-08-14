#include <bits/stdc++.h>
using namespace std;

// This is absolutely same as directed, just have a parent clause also
// check if parent is not there
// But this is O(V)
// We can do this in O(log V)
// using DSUF rank and path compression method
// Disjoin set union find


vector<int> adj[300005];
vector<bool> solved;

bool isCyclicUtil(vector<bool> &visited, int curr, int parent) {
    if (visited[curr]) return true;
    
    // DP so that not computing already computed
    if (solved[curr]) return false;

    solved[curr] = visited[curr] = true;
    bool flag = false;

    for(int i = 0; i < adj[curr].size(); i++) {

        if (adj[curr][i] == parent) continue;

        flag = isCyclicUtil(visited, adj[curr][i], curr);
        if (flag) return true;
    }

    visited[curr] = false;
    return false;
}

bool isCyclic(int V) {
    vector<bool> visited(V, false);
    bool flag = false;

    for(int i = 0; i < V; i++) {
        if(solved[i]) continue;

        for(int j = 0; j < adj[i].size(); j++) {
            flag = isCyclicUtil(visited, adj[i][j], -1);
            if (flag) return true;
        }
    }

    return false;
}

int solve(int A, vector<vector<int> > &B) {

    solved.clear();
    solved.resize(A + 2, false);
    for(int i = 0; i < 3e5 + 5; i++) adj[i].clear();

    for(int i = 0; i < B.size(); i++) {
        adj[B[i][0] - 1].push_back(B[i][1] - 1);
        adj[B[i][1] - 1].push_back(B[i][0] - 1);
    }

    return isCyclic(A);
}

int main () {

    // 1 to 3
    int vertices = 3;

    vector<vector<int>> VE = {
        {1, 2},
        {2, 3},
        {3, 1}
    };

    // 1 if cyclic else 0
    cout << solve(vertices, VE) << "\n";

}
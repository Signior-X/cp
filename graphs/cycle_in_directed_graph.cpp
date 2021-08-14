#include <bits/stdc++.h>
using namespace std;

// Best way
// As able to solve with TLE on both leetcode and interviewbit with this code
// The best way with meomization and dfs

// https://leetcode.com/problems/course-schedule/discuss/1388513/C%2B%2B-Solution-oror-Topological-Sort-oror-90-Faster
// See this also


vector<int> adj[100005];
vector<bool> solved;

bool isCyclicUtil(vector<bool> &visited, int curr) {
    if (visited[curr]) return true;
    
    if (solved[curr]) return false;

    solved[curr] = visited[curr] = true;
    bool flag = false;

    for(int i = 0; i < adj[curr].size(); i++) {
        flag = isCyclicUtil(visited, adj[curr][i]);

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
            flag = isCyclicUtil(visited, adj[i][j]);
            if (flag) return true;
        }
    }

    return false;
}


int solve(int A, vector<vector<int> > &B) {


    // Creating adjacenly list


    // Numbered 1 to A
    // So, storing a node 
    solved.clear();
    solved.resize(A + 2, false);

    for(int i = 0; i < 100005; i++) {
        adj[i].clear();
    }

    for(int i = 0; i < B.size(); i++) {
        adj[B[i][0] - 1].push_back(B[i][1] - 1);
    }

    // for(int i = 0; i < A; i++) {
    //     for(int &vl : adj[i]) cout << vl << " ";
    //     cout << " NN ";
    // }

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
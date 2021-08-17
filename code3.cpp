#include <bits/stdc++.h>
using namespace std;

#define test int T; cin >> T; while(T--)
#define printv(ele) for(auto &vl : ele) cout << vl << " "; cout << "\n";

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>

int find_set(vi &parent, int v) {
    if (v == parent[v]) return v;

    return parent[v] = find_set(parent, parent[v]);
}

void union_sets(vi &parent, vi &ranki, int a, int b) {
    a = find_set(parent, a);
    b = find_set(parent, b);

    if (a != b) {
        // a higher rank
        if (ranki[a] < ranki[b]) swap(a, b);

        parent[b] = a;
        if (ranki[a] == ranki[b]) ranki[a]++;
    }
}

int main() {
    int n, e1, e2;
    cin >> n >> e1 >> e2;

    // Graph for 1st and Graph for 2nd
    vi parent1(n, 0);
    vi rank1(n, 0);
    vi parent2(n, 0);
    vi rank2(n ,0);

    for(int i = 0; i < n; i++) {
        parent2[i] = i;
        parent1[i] = i;
        rank1[i] = 0;
        rank2[i] = 0;
    }

    for(int i = 0; i < e1; i++) {
        int a, b;
        cin >> a >> b;
        union_sets(parent1, rank1, a - 1, b - 1);
    }

    for(int i = 0; i < e2; i++) {
        int a, b;
        cin >> a >> b;
        union_sets(parent2, rank2, a - 1, b - 1);
    }

    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if ((find_set(parent1, i) != find_set(parent1, j))
                && (find_set(parent2, i) != find_set(parent2, j))) {
                ans.push_back({i + 1, j + 1});
                union_sets(parent1, rank1, i, j);
                union_sets(parent2, rank2, i, j);
            }
        }
    }

    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << " " << ans[i][1] << "\n";
    }
}
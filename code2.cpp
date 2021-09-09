#include <bits/stdc++.h>
using namespace std;

#define test int T; cin >> T; while(T--)
#define printv(ele) for(auto vl : ele) cout << vl << " "; cout << "\n";

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>

int find_min(int ar[], int start, int n) {
    int ans = 0;

    int curr = start;
    vector<int> zeroes;
    vector<int> ones;

    for(int i = 0; i < n; i++) {
        if (curr != ar[i]) {
            if (ar[i] == 0) zeroes.push_back(i);
            else ones.push_back(i);
        }

        curr = 1 - curr; 
    }

    if (ones.size() != zeroes.size()) return INT_MAX;

    for(int i = 0; i < ones.size(); i++) {
        ans += (max(ones[i], zeroes[i]) - min(ones[i], zeroes[i]));
    }

    return ans;
}

int process() {
    int n; cin >> n;
    int ar[n];
    for(int i = 0; i < n; i++) cin >> ar[i];

    if(n == 1) return 0;

    vector<int> mp(2, 0);
    for(int i = 0; i < n; i++) {
        int rm = ar[i] % 2;
        mp[rm]++;
        ar[i] = rm;
    }

    if (abs(mp[0] - mp[1]) > 1) return -1;

    int a1 = find_min(ar, 0, n);
    int a2 = find_min(ar, 1, n);

    return min(a1, a2);
}

void solve() {
    cout << process() << "\n";
}

int main() {
    // process();

    test solve();
    return 0;
}
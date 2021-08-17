#include <bits/stdc++.h>
using namespace std;

#define printv(ele) for(auto &vle : ele) cout << vle << " "; cout << "\n";
#define test int T; cin >> T; while(T--)

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>

int mod3(int n) {
    int md = n % 3;
    return md < 0 ? md + 3 : md;
}

void solve() {
    int n;
    cin >> n;

    vi ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    vvi matr(3, vi(3, 0));
    vi indCount(3, 0);
    vi numCount(3, 0);

    // First of all loop
    for(int i = 0; i < n; i++) {
        indCount[mod3(i)]++;
        numCount[mod3(ar[i])]++;

        if (mod3(i) != mod3(ar[i])) {
            matr[mod3(i)][mod3(ar[i])]++;
        }
    }

    bool poss = true;
    for(int i = 0; i < 3; i++) {
        if (indCount[i] != numCount[i]) poss = false;
    }

    if (!poss) {
        cout << -1 << "\n";
    } else {
        // for(auto &vl : matr) { printv(vl); }

        // check if opposite pairs exists or not
        int ans = 0;
        vvi pairs = {{1, 0}, {1, 2}, {0, 2}};

        for(vi &pp : pairs ) {
            int mn = min(matr[pp[0]][pp[1]], matr[pp[1]][pp[0]]);
            matr[pp[0]][pp[1]] -= mn;
            matr[pp[1]][pp[0]] -= mn;

            ans += mn;
        }

        ans += 2 * (matr[0][2] + matr[2][0]);

        // for(auto &vl : matr) { printv(vl); }

        cout << ans << "\n";
    }
}

int main () {
    test solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define test int T; cin >> T; while(T--)
#define printv(ele) for(auto &vl : ele) cout << vl << " "; cout << "\n";

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>


// Range provided matters a lot !!
// use -1 to n
// and pass the r

int lowerBound(vector<int> & v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

int upperBound(vector<int> & v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] > key)
            r = m;
        else
            l = m;
    }

    return r;
}

int main () {

    vi v = {1, 4, 5, 5, 7, 8, 8, 8};

    for(int i = 0; i <= 10; i++) {
        cout << i << " " << lower_bound(v.begin(), v.end(), i) - v.begin() << " " << lowerBound(v, -1, v.size(), i) << "\n";
    }


    for(int i = 0; i <= 10; i++) {
        cout << i << " " << upper_bound(v.begin(), v.end(), i) - v.begin() << " " << upperBound(v, -1, v.size(), i) << "\n";
    }

    return 0;
}
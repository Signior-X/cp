#include <bits/stdc++.h>

using namespace std;

#define ll long long int

bool cmp (int a, int b) {
    // jsut return what we want
    return a > b;
}

int main () {
    vector <int> v = { 1, 5, 2, 4, 8 };

    // we are using cmp as a comparator function here
    sort(v.begin(), v.end(), cmp);

    for (int val : v) {
        cout << val << " ";
    }

    cout << "\n";

    return 0;
}
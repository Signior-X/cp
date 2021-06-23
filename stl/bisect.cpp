// same as binary search folder just using stl here

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{

    // The way we use lower_bound and upper_bound in set and maps
    // is different - Important point

    vector<int> v = {1, 3, 4, 4, 4, 7, 8};

    for (int key = 0; key <= v[v.size() - 1] + 2; key++)
    {
        auto it = lower_bound(v.begin(), v.end(), key);
        auto it2 = upper_bound(v.begin(), v.end(), key);
        cout << key << " " << it - v.begin() << " " << it2 - v.begin() << "\n";
    }

    return 0;
}
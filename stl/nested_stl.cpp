#include <bits/stdc++.h>
using namespace std;

#define ll long long

// https://youtu.be/zyGSg3U1K94

int main () {

    // Pair priority is check first element, then second, then third and so on

    // Map of pair and int
    map<pair<int, int>, int> m;

    pair<int, int> p1, p2;
    p1 = {2, 3};
    p2 = {3, 4};

    m.insert({p2, 25});
    m.insert({p1, 12});

    for (auto &val : m) {
        cout << val.first.first << " " << val.first.second << " " << val.second << "\n";
    }

    // Map of set and int
    map<set<int>, int> m2;
    set<int> s1, s2;
    s1 = {3, 4, 5};
    s2 = {3, 4, 6};

    m2[s1] = 45;
    m2[s2] = 23;

    // Take care of not making copies
    for(auto &val : m2) {
        for (auto &val2 : val.first) {
            cout << val2 << " ";
        }

        cout << "\t " << val.second << "\n";
    }

    // Can also be done with vector
    // Also values can also be some complex structure, so like example

    // marks, name and have priority, so have
    // map<int, multiset<string>>
    // int for marks and set for names
    // Take care "set" is not used, to be used, use "multisets"

    // For descending, you can always think of "minus"
    // Minus can help a lot
    // Very useful trick

    return 0;
}
// KMP is the famous algorithm for this

#include <bits/stdc++.h>
using namespace std;

bool is_matching(string &m, string &st, int start_index) {

    cout << st.substr(start_index, m.length()) << "\n";

    // if (st.substr(start_index, m.length()) == m) return true;

    for(int i = 0; i < m.length(); i++) {
        if (st[i + start_index] != m[i]) return false;
    }

    return true;
}

int main () {

    string st = "AABAACAADAABAABA";
    string m = "AABA";

    vector<int> ans;

    // Total time O(m(n-m+1))
    for (int i = 0; i + m.length() - 1 < st.length(); i++) {
        // cout << "Checking " << i << "\n";
        if (is_matching(m, st, i)) ans.push_back(i);
    }

    // We can optimise it better using KMP algorithm
    // See KMP LPS array
    // See https://www.youtube.com/watch?v=GTJr8OvyEVQ
    // O (m + n)

    for(auto &val : ans) {
        cout << val << " ";
    }

    cout << "\n";

    return 0;
}
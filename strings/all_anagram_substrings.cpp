#include <bits/stdc++.h>
using namespace std;

bool check_if_hash_equal(int *h1, int *h2, int l) {
    // Both are 26 length arrays
    for(int i = 0; i < l; i++) {
        if (h1[i] != h2[i]) return false;
    }

    return true;
}

vector<int> solve(string &st, string &m) {
    vector<int> ans = {};

    if (m.length() > st.length()) {
        return ans;
    }

    int l = 26;
    int hash_m[l] = {0};
    int hash_tmp[l] = {0};

    for (char ch : m) {
        hash_m[ch - 97]++;
    }

    int m_length = m.length();
    for (int i = 0; i < m_length; i++) {
        hash_tmp[st[i] - 97]++;
    }

    // Now loop
    for(int i = 0; i + m_length <= st.length(); i++) {

        if (check_if_hash_equal(hash_tmp, hash_m, l)) {
            ans.push_back(i);
        }

        // Now remove the ith one and add the i + m_length
        if (i + m_length < st.length()) {
            hash_tmp[st[i] - 97]--;
            hash_tmp[st[i + m_length] - 97]++;
        }
    }

    return ans;
}

int main () {
    // Find the anagrams of m in st
    // Only small characters
    string st, m;
    cin >> st;
    cin >> m;

    vector<int> ans = solve(st, m);

    for(int &val : ans) {
        cout << val << " ";
    }

    cout << "\n";
}
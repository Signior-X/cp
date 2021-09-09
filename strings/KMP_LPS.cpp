#include <bits/stdc++.h>
using namespace std;


vector<int> make_pi(string &s) {
    int n = s.length();

    vector<int> pi(n, 0);
    for(int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;

        pi[i] = j;
    }

    return pi;
}

bool check_if_substring(string s, string t) {
    string ns = t + '#' + s;

    cout << ns << "\n";

    int l = t.length();
    vector<int> pi = make_pi(ns);

    for(int i = 0; i < pi.size(); i++) {
        if (pi[i] == l) return true;
    }

    return false;
}


void old() {
    string s = "bba";
    int l = s.length();
    vector<int> lps(l);

    int j = 0, i = 1;
    while(i < s.length()) {
        // Two cases -> Match or mismatch
        if (s[i] == s[j]) {
            lps[i] = j + 1;
            i++;
            j++;
        } else {
            // mismatch, don't worry just see j
            if (j==0) {
                // No more backward possible
                lps[i] = 0;
                i++;
            } else {
                j = lps[j-1];
            }
        }
    }

    int mx = lps[l-1];
    int mxi = l-1;

    // Now what we want is let's say count is 5
    cout << s.substr(mxi - mx + 1, mx) << "\n";

}

int main() {

    // a b c d a b c a
    // 0 0 0 0 1 2 3 1
    // To generate LPS array
    // We keep two pointers, and then two conditions
    // If they match, increment both and store
    // If not, keep moving backwards with j to find
    // until it find the same

    string t = "priyam";
    string s = "priyam";

    cout << check_if_substring(t, s) << "\n";

    return 0;
    
}
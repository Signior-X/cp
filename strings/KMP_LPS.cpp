#include <bits/stdc++.h>
using namespace std;

int main() {

    // a b c d a b c a
    // 0 0 0 0 1 2 3 1
    // To generate LPS array
    // We keep two pointers, and then two conditions
    // If they match, increment both and store
    // If not, keep moving backwards with j to find
    // until it find the same

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

    return 0;
}
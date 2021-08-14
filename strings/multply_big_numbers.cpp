#include <bits/stdc++.h>
using namespace std;

string addS(string &s1, string &s2) {

    // Adds two strings numbers
    // 3 4 5
    // 4 5 6 7

    // s2 must be smaller
    if (s2.length() > s1.length()) return addS(s2, s1);

    // Now s2 is smaller string

    // we make them of equal length for ease
    int diff = s1.length() - s2.length();
    while(diff) {
        s2 = '0' + s2;
        diff--;
    }

    int crr = 0;
    string ans = s1;

    // We are now taking both of same length
    int a = s1.length() - 1;
    int b = s2.length() - 1;
    while(b >= 0) {

        int s2v = (int)(s2[b] - 48);
        int s1v = (int)(s1[a] - 48);

        int sm = s2v + s1v + crr;
        ans[a] = (char)((sm % 10) + 48);
        crr = sm / 10;

        a--;b--;
    }

    if (crr) {
        ans = "1" + ans;
    }

    return ans;
}

string addSRev(string &s1, string &s2) {
    // Just trying addS with another approach
    // we reverse both the strings

    string sr1 = string(s1.rbegin(), s1.rend());
    string sr2 = string(s2.rbegin(), s2.rend());

    string s3r = "";
    int l1 = s1.length();
    int l2 = s2.length();

    int crr = 0;
    int i = 0;

    while(i < l1 || i < l2) {
        int vl1 = 0;
        int vl2 = 0;

        if (i < l1) vl1 = (int)(sr1[i] - 48);
        if (i < l2) vl2 = (int)(sr2[i] - 48);

        int sm = vl1 + vl2 + crr;
        crr = sm / 10;
        s3r += (char)( (sm % 10) + 48);

        i++;
    }

    if (crr) {
        s3r += (char)(crr + 48);
    }

    reverse(s3r.begin(), s3r.end());

    return s3r;
}



string multOne(string &s1, int vl) {

    // 789 * 9
    // Now s2 is smaller string
    // we make them of equal length for ease

    int crr = 0;
    string ans = "";

    // We are now taking both of same length
    int a = s1.length() - 1;
    
    while(a >= 0) {
        int s1v = (int)(s1[a] - 48);

        int sm = (vl * s1v) + crr;
        ans = (char)((sm % 10) + 48) + ans;
        crr = sm / 10;

        a--;
    }

    if (crr) {
        ans = char(crr + 48) + ans;
    }

    return ans;
}

string multiply(string A, string B) {
    
    string ans = "0";
    int i = B.length() - 1;
    string fc = "";

    while(i >= 0) {

        string crs = multOne(A, (int)(B[i] - 48)) + fc;
        ans = addS(ans, crs);

        fc += "0";
        i--;
    }

    // Instead count upto what number is zeroes and use erase
    // Remove trailing spaces
    int upto = 0;
    for(int i = 0; i < ans.length() - 1; i++) {
        if (ans[i] == '0') upto++;
        else break;
    }

    ans.erase(0, upto);

    return ans;
}


int main () {

    string a, b;
    cin >> a >> b;
    cout << addS(a, b) << "\n";
    cout << addSRev(a, b) << "\n";
    cout << multiply(a, b) << "\n";

    return 0;
}

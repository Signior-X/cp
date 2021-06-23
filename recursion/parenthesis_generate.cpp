#include <bits/stdc++.h>
using namespace std;

#define ll long long int

vector<string> ans;


// Take care of what are you using
// pass by reference or pass by value
void generate(string &s, int open, int close) {
    if (open == 0 && close == 0) {
        ans.push_back(s);
        return;
    }

    if (open > 0) {
        s.push_back('(');
        generate(s, open - 1, close);
        s.pop_back();
    }

    if (close > 0 && open < close) {
        s.push_back(')');
        generate(s, open, close - 1);
        s.pop_back();
    }
}

int main () {

    int n = 3;
    string s = "";
    generate(s, n, n);

    for (string val: ans) {
        cout << val << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define long long ll

vector<string> ans;

void generate(string s, int curr, string given) {
    if (curr == 3) {
        ans.push_back(s);
        return;
    }
    
    for(int i = 0; i < given.length(); i++) {
        generate(s + given[i], curr + 1, given);
    }
}

int main () {
    string s = "abc";

    generate("", 0, s);

    for(auto val : ans) cout << val << "\n";
    cout << ans.size() << "\n";

}
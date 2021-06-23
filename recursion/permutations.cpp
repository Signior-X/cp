// Try to generate all permutaions of something
// abc
// acb
// bac
// bca
// cab
// cba

#include <bits/stdc++.h>
using namespace std;

#define long long ll

vector<string> ans;

void generate(string &s, int low, int high)
{
    // cout << s << " " << low << " " << high << "\n";

    if (low == high)
    {
        ans.push_back(s);
        return;
    }

    for (int i = low; i <= high; i++)
    {
        // swap
        swap(s[low], s[i]);

        // Go more inside
        generate(s, low + 1, high);

        // Backtrack
        swap(s[low], s[i]);
    }
}

int main()
{
    string s = "abc";

    generate(s, 0, s.length() - 1);


    for(auto val : ans) cout << val << "\n";
    cout << ans.size() << "\n";

}
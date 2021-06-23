#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{

    // 2 5 3 9 1 6
    // We need to find the next greater element for each element
    // 5 9 9 -1 6 -1
    // -1 if does not exist

    // A good question that uses stack

    int n;
    cin >> n;

    int ar[n];

    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    // Value, index
    stack<pair<int, int>> stck;
    pair<int, int> ans[n];  // vAlue, index

    for (int i = 0; i < n; i++)
    {

        while (!stck.empty() && stck.top().first < ar[i])
        {
            pair<int, int> val = stck.top();
            ans[val.second] = {ar[i], i};

            stck.pop();
        }

        // After poping push it into stack

        stck.push({ar[i], i});
    }

    while(!stck.empty()) {
        ans[stck.top().second] = {-1, -1};
        stck.pop();
    }

    for(pair<int, int> val : ans) {
        cout << val.first << " " << val.second << "\n";
    }

    cout << "\n";

    return 0;
}
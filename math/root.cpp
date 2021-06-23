#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main() {
    
    ll a = 999999999999;
    
    // Use sqrtl for very long number
    long double val = sqrtl(a);

    if (val < 10e6) {
        cout << "YES";
    } else {
        cout << "No";
    }

    return 0;
}
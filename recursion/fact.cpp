#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define print(x) cout << x << "\n"

ll fact(int n) {
    if (n == 1 || n == 0) return 1;

    return n*fact(n-1);
}

int main() {
    int n = 10;

    ll fac = fact(n);
    print(fac);
    
    return 0;
}

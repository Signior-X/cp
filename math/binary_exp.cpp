#include <bits/stdc++.h>

using namespace std;

int power(int x, int y, int p)
{
    int res = 1;     // Initialize result
 
    x = x % p;
  
    if (x == 0) return 0;
 
    while (y > 0)
    {

        if (y & 1)
            res = (res * 1LL * x) % p;
 

        y = y >> 1;
        x = (x * 1LL * x) % p;
    }

    return ( res >=0 ) ? res : (p + res);
}

int pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return power(x, n, d);
}

int main () {

    // 1LL was important
    cout << pow(2, 3, 5) << "\n";

    return 0;
}
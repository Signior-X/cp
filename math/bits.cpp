#include <bits/stdc++.h>
using namespace std;

#define ll long long int

string toBinary(int val) {
    // Conversts a number into its binary string
    string ans = "";
    while(val) {
        // Get the leftmost bit
        if (val & 1) {
            ans = "1" + ans;
        } else {
            ans = "0" + ans;
        }

        val = val >> 1;
    }

    return ans;
}

int main () {

    int i;

    // 1100
    int a = 12;
    cout << a << " " << toBinary(a) << "\n";

    // Checking if a bit is set or not
    i = 1;
    if ((a & (1<<i)) == 0) cout << i << " bit unset\n";
    else cout << i << " bit is set\n";

    // Setting a bit
    int bitSet = (a | ( 1 << i ));
    cout << bitSet << " " << toBinary(bitSet) << "\n";

    // Unsetting a bit
    int bitUnSet = (bitSet & ~( 1 << i ));
    cout << bitUnSet << " " << toBinary(bitUnSet) << "\n";

    // Toggle a bit, we generally use xor
    int toggleBit = (a ^ (1 << i));
    cout << toggleBit << " " << toBinary(toggleBit) << "\n";

    // Count number of set bits
    int b = a, s = 0;
    while(b) {
        s += (b & 1);
        b = b >> 1;
    }
    cout << "Number of bits = " << s << " in " << toBinary(a) << "\n";
    cout << "Using inbuild function = " << __builtin_popcount(a) << "\n";

    return 0;
}
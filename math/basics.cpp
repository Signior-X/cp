#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

// They take unsigned values so take care however
// clz -> count leading zeroes considering int
// ctz -> count trailing zeroes considering int
// Add l, ll  for long and long long
// https://codeforces.com/blog/entry/45966

int log(ll x) {
	return 64 - __builtin_clzll(x) - 1;
}

int log(int x) {
    return 32 - __builtin_clz(x) - 1;
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int binExp(int a, int b) {
	int M = 1e9 + 7;

	a %= M;
	int res = 1;

	while(b) {
		if (b & 1) res = (res * 1LL * a) % M;
		a = (a * 1LL * a) % M;
		b >>= 1;
	}

	return res;
}


int main () {

	// binary exponentiation
	// here we have problems when long long
	// as it exceeds, so we are wiriting here only
	// for int int
	cout << binExp(1000000000, 1000000000) << "\n\n";



	// count number of digits -> toString is best or use floor(log10(n) + 1)
	// log 10 -> use inbuilt function



	// Finding floor of log in O(1)
	// Finding floor square root in O(1)
	
	int END = 2;

	for(int i = 1; i <= END; i++) {
		cout << i << ": " << log(i) << " " << floor(sqrtl(i)) << "\n";
	}

	cout << "\n";





	// Floor and ceil
	// For ceil use (a + b - 1) / b
	// In case of division

	for(int i = 0; i <= END; i++) {
		cout << i << ": " << (i / 3) << " " << (i + 2) / 3 << "\n";
	}



	// For finding hcf and lcm of two numbers
	cout << "\n" << gcd(10, 20) << "\n";




	// Now some basic bit manipulation
	int a = 20;
	bitset<32> aset(a);

	// Bitset is best for bit manipulations
	// can use indexing in reverse order as we have in bits
	cout << aset << "\n";
	aset[1] = 1;
	cout << aset.to_ullong() << "\n";

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

// Array print can give some errors
void print(int val) { cout << val << "\n"; }
void print(string st) { cout << st << "\n"; }
void print(ll val) { cout << val << "\n"; }
void print(int *ar) { int l = sizeof(ar) / sizeof(ar[0]); for(int i = 0; i < l; i++) { cout << ar[i] << " "; } cout << "\n"; }
void print(string *ar) { int l = sizeof(ar) / sizeof(ar[0]); for(int i = 0; i < l; i++) { cout << ar[i] << " "; } cout << "\n"; }
void print(ll *ar) { int l = sizeof(ar) / sizeof(ar[0]); for(int i = 0; i < l; i++) { cout << ar[i] << " "; } cout << "\n"; }
void print(vector<int> &v) { for(int &val : v) cout << val << " "; cout << "\n"; }
void print(vector<string> &v) { for(string &val : v) cout << val << " "; cout << "\n"; }
void print(vector<ll> &v) { for(ll &val : v) cout << val << " "; cout << "\n"; }
void print(vector<pair<int, int>> &v) { for (pair<int, int> &val : v) cout << val.first << " " << val.second << "\n"; }
void print(vector<pair<ll, ll>> &v) { for (pair<ll, ll> &val : v) cout << val.first << " " << val.second << "\n"; }

ll binExp(ll a, ll b) {

    ll res = 1;

    while(b) {
        if (b & 1) res = (res * 1LL * a);
        a = (a * 1LL * a);
        b >>= 1;
    }

    return res;
}


int main () {

	for(ll i = 0; i < 64; i++) {
		cout << binExp(2, i) << "\n";
	}

}
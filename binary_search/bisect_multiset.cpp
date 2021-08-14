#include <bits/stdc++.h>
using namespace std;

int main () {

	multiset<int>  ms;

	ms.insert(5);
	ms.insert(13);

	multiset<int>::iterator it = ms.upper_bound(4);

	cout << *it << "\n";

	return 0;
}
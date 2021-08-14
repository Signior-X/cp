#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

vi parent;
vi ranki;

int find_set(int v) {
	if (v == parent[v]) return v;

	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);

	if (a != b) {
		// a higher rank
		if (ranki[a] < ranki[b]) swap(a, b);

		parent[b] = a;
		if (ranki[a] == ranki[b]) ranki[a]++;
	}
}

int main() {
	
	int n = 10; // 0 to 9
	for(int i = 0; i < n; i++) {
		parent.push_back(i);
		ranki.push_back(0);
	}

	union_sets(3, 1);
	union_sets(1, 2);
	
	union_sets(6, 7);
	union_sets(7, 8);

	union_sets(9, 5);

	union_sets(4, 0);

	union_sets(4, 3);
	union_sets(9, 6);

	union_sets(9, 4);

	find_set(3);

	for(int i = 0; i < n; i++) {
		cout << i << " " << parent[i] << " " << ranki[i] << "\n";
	}

	return 0;
}
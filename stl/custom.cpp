#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct coprime {
	stack<int> s, x;

	coprime() {
		s.push(0);
		x.push(0);
	}

	void push(int vl) {
		s.push(vl);
		x.push(vl * vl);
	}

	int pop() {
		int vl = x.top();
		s.pop();
		x.pop();

		return vl;
	}

	int size() {
		return s.size() + x.size();
	}

	string toString() {
		string str = "";



		return str;
	}
};

int main () {

	coprime cpr;


	return 0;
}
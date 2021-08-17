#include <bits/stdc++.h>
using namespace std;

#define test int T; cin >> T; while(T--)
#define printv(ele) for(auto &vl : ele) cout << vl << " "; cout << "\n";
#define printm(ele) for(auto &vl : ele) cout << vl.first << " " << vl.second << "\n"; cout << "\n";

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>

struct Trie {
	bool ending;
	int cnt;
	map<char, Trie*> mp;

	Trie() {
		ending = false;
		cnt = 0;
	}
};

void insertWord(Trie* &root, string s) {
    Trie* p = root;

    for(int i = 0; i < s.length(); i++) {
        (p -> cnt)++;

        if ((p -> mp).find(s[i]) == (p -> mp).end()) {
	        (p -> mp)[s[i]] = new Trie();
	    }

	    // printm(p -> mp);
	    p = (p -> mp)[s[i]];
    }

    p -> ending = true;
}

void dfsTree(Trie* &root, string curr) {
    if (root -> ending) cout << curr << " ";

    if (root -> mp.size() == 0) return;

    for(auto &mp : root -> mp) {
        dfsTree(mp.second, curr + mp.first);
    }
}

string search(Trie* &root, string key)
{
    string res;
    Trie* temp = root;

    for(int i = 0; i < key.length(); i++) {
        res.push_back(key[i]);

        temp = (temp -> mp)[key[i]];
        if(temp -> cnt == 1) break;
    }

    return res;
}

int main() {
	Trie* root = new Trie();

	insertWord(root, "hello");
	insertWord(root, "help");
	insertWord(root, "wow");
	insertWord(root, "priyam");
	insertWord(root, "okay");

	dfsTree(root, "");
	return 0;
}
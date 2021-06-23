#include <bits/stdc++.h>
using namespace std;

void create_hash(string &s, vector<int> &hashAr) {
	for(int i=0; i < s.length(); i++) {
		hashAr[s[i] - 'a']++;
	}
}


bool check_hash1_occupies_hash2(vector<int> hash1, vector<int> hash2) {
	// Assumes hash to be of size 26
	// and hash1 contains all from hash2

	for(int i = 0; i < 26; i++) {
		if (hash2[i] != 0) {
			// It contains atleast of that
			if (hash1[i] < hash2[i]) return false;	
		}
	}

	return true;
}


int main () {
	
	string s = "azjsfkzts";
	string ch = "sz";
	
	vector<int> hash_s(26);
	vector<int> hash_ch(26);

	create_hash(ch, hash_ch);
	hash_s[s[0] - 'a']++;

	// Now keep the two pointers approach
	int j = 0, i = 0;
	int mnj = 0, mni = s.length();

	while(i < s.length()) {

		if(check_hash1_occupies_hash2(hash_s, hash_ch)) {
			// We will shrink the window by also moving j


			// First update if shorter
			if ((i - j + 1) < (mni - mnj + 1)) {
				mni = i;
				mnj = j;
			}

			hash_s[s[j] - 'a']--;
			j++;

		} else {
			// Hash not equal, we need to expand the window
			i++;
			hash_s[s[i] - 'a']++;
		}
	}

	cout << mni << " " << mnj << "\n";

	return 0;
}
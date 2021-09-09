#include <bits/stdc++.h>
using namespace std;

#define test int T; cin >> T; while(T--)
#define printv(ele) for(auto vl : ele) cout << vl << " "; cout << "\n";

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>

struct Trie {
    vector<Trie*> child;
    int isLeaf;

    Trie() {
        isLeaf = false;
        child = {NULL, NULL};
    }
};

void insert_trie(Trie *head, int vl) {
    bitset<32> bset(vl);

    Trie* itr = head;
    for(int i = 31; i >= 0; i--) {
        // cout << bset[i] << " ";
        if ((itr -> child)[bset[i]] == NULL) {
            (itr -> child)[bset[i]] = new Trie();
        }

        itr = (itr -> child)[bset[i]];
    }

    itr -> isLeaf = true;
}


void print_trie(Trie* head, string &curr) {
    if (head == NULL) return;

    if (head -> isLeaf) {
        cout << curr << "\n";
        return;
    }

    if ((head -> child)[0] != NULL) {
        curr.push_back('0');
        print_trie((head -> child)[0], curr);
        curr.pop_back();
    }

    if ((head -> child)[1] != NULL) {
        curr.push_back('1');
        print_trie((head -> child)[1], curr);
        curr.pop_back();
    }
}

int find_max_xor(Trie* head, int curr_xor) {
    int res = 0;

    bitset<32> bset(curr_xor);
    bitset<32> bset2;

    Trie* itr = head;
    for(int i = 31; i >= 0; i--) {
        if ((itr -> child)[1 - bset[i]]) {
            bset2[i] = 1 - bset[i];
            itr = (itr -> child)[1 - bset[i]];
        } else {
            bset2[i] = bset[i];
            itr = (itr -> child)[bset[i]];
        }
    }

    bitset<32> ans = bset ^ bset2;

    // cout << ans << "\n";

    return (int)ans.to_ullong();
}

void solve() {
    vi v = {1, 2, 3, 4};
    int n = v.size();

    // Add prefix xors and keep finding the max values
    Trie* head = new Trie();
    insert_trie(head, 0);

    string curr;

    int ans = 0;

    int curr_xor = 0;
    for(int i = 0; i < n; i++) {
        curr_xor = curr_xor ^ v[i];

        // Find the maximum value that can be generated
        int mxXor = find_max_xor(head, curr_xor);
        ans = max(ans, mxXor);

        insert_trie(head, curr_xor);
    }

    // print_trie(head, curr);

    cout << ans << "\n";
}

int main() {

    test solve();
    return 0;
}

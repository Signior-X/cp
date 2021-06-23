#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void print_set(set<string> s) {
    for(auto val: s) {
        cout << val << " ";
    }

    cout << "\n";
}

int main () {

    // Set is the best because of O(logn)
    // Stores in sorted order
    // It does not have any indexing like in map, vectors etc
    // Multisets can be used as priority queue also

    set <string> s;
    s.insert("hello");
    s.insert("world");
    s.insert("priyam");
    
    print_set(s);

    // We use find to check if the value exists or not
    auto it = s.find("priyam");

    while(it != s.end()) {
        cout << *it << "\n";
        it++;
    }


    // In case of multiset, it points to the first pointer
    // If you need erase, it removes all of them
    // If you want to erase, generally use iterator to delete the value
    // Multiset can be very useful and can be used many times as
    // a replacement of map or heap

    return 0;
}
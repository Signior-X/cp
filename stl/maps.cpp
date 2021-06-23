#include <bits/stdc++.h>

using namespace std;

// Map use RBT, so of O(logn)
// In case of string, O(length of string * logn)
// unordered_map uses hashing, so O(1) to O(n)

// Peferred way
void print_map(map<int, string> &m) {
    for(auto &val : m) {
        cout << val.first << " " << val.second << "\n";
    }
}

void print_map2(map<int, string> &m) {
    for(auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << (*it).second << "\n";
    }
}

int main () {

    map<int, string> m;
    m[2] = "Hello";
    m[4] = "World";
    m[1] = "First";

    m.insert({6, "Priyam"});

    // Printing the map
    print_map(m);

    // Finding in the map
    // It returns the iterator or m.end() if not found

    // Can also use auto here
    int key = 2;
    map<int, string> ::iterator it = m.find(key);
    
    if (it == m.end()) {
        cout << key << " Not Found" << "\n";
    } else {
        cout << key << " Found with value: " << it->second << "\n";
    }

    // Erasing a key
    m.erase(10); // key
    print_map2(m);

    // Also unordered_map is generally not used
    // However it can used to generate a hash function
    // As you can see in this question
    // https://youtu.be/q-JB0hYyouo

    return 0;
}
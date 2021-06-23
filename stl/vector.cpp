#include <bits/stdc++.h>

using namespace std;

void print_vec(vector<int> &vec) {
    // Use &val or val
    // & will be reference else
    // without this it will copy it
    // See references

    for(int &val : vec) {
        cout << val << " ";
    }

    cout << "\n";
}

void print_vec2(vector<int> &vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    cout << "\n";
}

// & for pass by reference
// If we use simple, it is pass by value
void print_vec3(vector<int> &vec) {
    for (vector<int> ::iterator it = vec.begin(); it < vec.end(); it++) {
        // it++ and it + 1 have a difference
        // it + 1 will not work in maps and sets as
        // They are not contiguous memory blocks
        // i + 1 points to next location
        // i ++ points to next iterator

        cout << *it << " ";
    }

    // (*it).first  <=>  it->first
    // In case we are using pairs
    
    cout << "\n";
}

void print_vec4(vector<int> &vec) {
    // Use can use `auto`, this is more like var in JavaScript
    // See it is not equal to here
    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << *it << "\n";
    }

    cout << "\n";
}

int main () {

    vector <int> v(5);

    print_vec(v);
    print_vec2(v);
    print_vec3(v);

    cout << v.size() << "\n";

    return 0;
}
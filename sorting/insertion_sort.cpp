#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define print(x) cout << x << "\n";

void swap(int *ar, int i, int j) {
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}

int main() {

    // Insertion sort
    // Loop and Keep dividing it into sorted part
    // Loop and keep moving the element above it

    int ar[] = { 3, 5, 10, 2, 4, 7};
    int l = sizeof(ar) / sizeof(ar[0]);

    for (int i = 0; i < l; i++) {
        int key = ar[i];

        // Now move backward until key is smaller than the one you are checking
        // And keep swapping
        for (int j = i-1; j >= 0; j--) {
            if (key < ar[j]) swap(ar, j, j+1);
            // else break;
        }
    }

    for (int val : ar) {
        cout << val << " ";
    }

    cout << "\n";


    return 0;
}
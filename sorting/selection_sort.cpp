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

    // Selection sort
    // Loop and Keep dividing it into sorted part
    // Loop above and find the minimum to swap

    int ar[] = { 3, 5, 10, 2, 4, 7};
    int l = sizeof(ar) / sizeof(ar[0]);

    for (int i = 0; i < l; i++) {
        int key = ar[i];

        int mn = key;
        int mni = i;

        // Now loop in the unsorted part and find the minimum one to swap with ar[i]
        for (int j = i + 1; j < l; j++) {
            if (ar[j] < mn) {
                mn = ar[j];
                mni = j;
            }
        }

        swap(ar, i, mni);

    }

    for (int val : ar) {
        cout << val << " ";
    }

    cout << "\n";


    return 0;
}
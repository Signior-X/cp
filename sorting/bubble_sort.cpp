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

    // Bubble sort
    // Nested loop and keep swapping

    int ar[] = { 3, 5, 10, 2, 4, 7 };
    int l = sizeof(ar) / sizeof(ar[0]);

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            if (ar[j+1] < ar[j]) swap(ar, j, j+1);
        }
    }

    for (int val : ar) {
        cout << val << " ";
    }

    cout << "\n";


    return 0;
}
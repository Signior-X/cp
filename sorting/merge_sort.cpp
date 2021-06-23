#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define print(x) cout << x << "\n";

void merge(int *ar, int low, int mid, int high) {
    // Let's say we have two pieces in a sorted array
    // 1, 5, 8, 2, 5, 7

    // End result should be
    // 1, 2, 5, 5, 7, 8

    int l1 = mid - low + 1; // Low ... Mid
    int l2 = high - mid;  // Mid + 1 ... High

    int L[l1], R[l2];

    for (int i = 0; i < l1; i++) {
        L[i] = ar[low + i];
    }

    for (int j = 0; j < l2; j++) {
        R[j] = ar[mid + j + 1];
    }

    int i = 0 , j = 0;
    int k = low;

    while(i < l1 && j < l2) {
        if (L[i] <= R[j]) {
            ar[k] = L[i];
            i++;
        } else {
            ar[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < l1) {
        ar[k] = L[i];
        k++;
        i++;
    }

    while(j < l2) {
        ar[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int *ar, int low, int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;

    merge_sort(ar, low, mid);
    merge_sort(ar, mid + 1, high);

    merge(ar, low, mid, high);
}

int main() {

    // Merge sort
    // A divide and conquer approach
    // First divide and then combine and then keep combining two sorted pieces

    int ar[] = { 3, 5, 10, 2, 4, 7};
    int l = sizeof(ar) / sizeof(ar[0]);

    merge_sort(ar, 0, l-1);

    for (int val : ar) {
        cout << val << " ";
    }

    cout << "\n";


    return 0;
}
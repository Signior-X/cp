#include <bits/stdc++.h>

using namespace std;

void swap(vector<int> &ar, int i, int j) {
	int temp = ar[i];
	ar[i] = ar[j];
	ar[j] = temp;
}

int quick_select(vector<int> &ar, int low, int high) {
	// Make the element less the pivot
	// and return the pivot position

	// Chose a pivot
	// Let's say we chose last element as pivot
	int pivot = ar[high];
	int i = low - 1;
	int j = low;

	// checkign till the second last character
	for(j = low; j < high; j++) {
		if (ar[j] < pivot) {
			i++;
			swap(ar, i, j);
		}
	}

	swap(ar, i + 1, high);
	return i + 1;
}

int find(vector<int> &ar, int k, int low, int high) {

	int pivot = quick_select(ar, low, high);

	cout << "P " << pivot << "\n";

	if (pivot == k - 1) return ar[pivot];
	else if (pivot < k - 1) {
		find(ar, k, pivot + 1, high);
	} else {
		find(ar, k, low, pivot - 1);
	}
}

int main () {

	// Finding kth smallest or largest element
	// n logn by sorting
	// k logn by heaps
	// O(n) solved recursively in quickSelect // can also reach O(n^2)
	// Here we are going to use the quickSelect approach

	vector<int> ar = {7, 4, 6, 1, 9, 8, 3};
	int k = 4;

	int vl = find(ar, k, 0, ar.size() - 1);

	cout << vl << "\n";

	return 0;
}
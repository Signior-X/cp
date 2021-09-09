#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* next;

	Node(int v) {
		val = v;
		next = NULL;
	}
};


void printList(Node *node) {
	if (node == NULL) {
		cout << "\n";
		return;
	}

	cout << node -> val << " ";
	printList(node -> next);
}

Node* merge_lists(Node* a, Node *b) {
	if (a == NULL) return b;
	if (b == NULL) return a;

	// cout << a -> val << b -> val;

	if (a -> val > b -> val) swap(b, a);

	Node *itr1 = a;
	Node *itr2 = b;

	while(itr1 -> next) {
		if (itr1 -> next -> val <= itr2 -> val) {
			itr1 = itr1 -> next;
		} else {
			swap(itr1 -> next, itr2);
			itr1 = itr1 -> next;
		}
	}

	itr1 -> next = itr2;

	return a;
}

int main() {

	Node *r1 = new Node(2);
	r1 -> next = new Node(3);
	r1 -> next -> next = new Node(10);
	r1 -> next -> next -> next = new Node(20);

	Node *r2 = new Node(5);
	r2 -> next = new Node(8);
	r2 -> next -> next = new Node(15);
	r2 -> next -> next -> next = new Node(30);
	r2 -> next -> next -> next -> next = new Node(40);


	printList(r1);
	printList(r2);

	Node* r3 = merge_lists(r2, r1);

	printList(r1);
	printList(r2);

	printList(r3);

	return 0;
}
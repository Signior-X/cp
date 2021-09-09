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

Node* reverse_list(Node* start, Node* end = NULL) {
	if (start == NULL || start -> next == NULL || start == end) return start;

	Node *prev = start, *curr = start -> next;
	start -> next = end;

	while(curr != end) {
		Node* tmp = curr -> next;
		curr -> next = prev;

		prev = curr;
		curr = tmp;
	}

	return prev;
}


int main() {

	Node *r2 = new Node(5);
	r2 -> next = new Node(8);
	r2 -> next -> next = new Node(15);
	r2 -> next -> next -> next = new Node(30);
	r2 -> next -> next -> next -> next = new Node(40);

	printList(r2);

	Node *r3 = reverse_list(r2, r2 -> next -> next -> next);

	printList(r3);

	return 0;
}
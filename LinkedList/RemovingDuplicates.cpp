#include <iostream>
#include <cstring>
using namespace std;

typedef struct node {
	int data;
	node *next;
} node;
bool hashh[100];

node* init(int a[], int n) {
	node *head, *p;
	for (int i = 0; i < n; ++i) {
		node *nd = new node();
		nd->data = a[i];
		if (i == 0) {
			head = p = nd;
			continue;
		}
		p->next = nd;
		p = nd;
	}
	return head;
}

// Removing Duplicates using Extra Space by Using Hashh Array
// Using Temprory Buffering
void removedulicate1(node *head) {
	if (head == NULL) return;
	node *p = head, *q = head->next;
	hashh[head->data] = true;
	while (q) {
		if (hashh[q->data]) {
			node *t = q;
			p->next = q->next;
			q = p->next;
			delete t;
		}
		else {
			hashh[q->data] = true;
			p = q; q = q->next;
		}
	}
}


//Removing Duplicates Without Using Extra Space.
void removedulicate2(node *head) {
	if (head == NULL) return;
	node *p, *q, *c = head;
	while (c) {
		p = c; q = c->next;
		int d = c->data;
		while (q) {
			if (q->data == d) {
				node *t = q;
				p->next = q->next;
				q = p->next;
				delete t;
			}
			else {
				p = q; q = q->next;
			}
		}
		c = c->next;
	}
}
// 2 Pointer Approach
// Time Complexity = O(n^2)

void print(node *head) {
	while (head) {
		cout << head->data << " ";
		head = head->next;
	}
}
int main() {
	int n = 10;
	int a[] = {
		3, 2, 1, 3, 5, 6, 2, 6, 3, 1
	};
	memset(hashh, false, sizeof(hashh));
	node *head = init(a, n);
	removedulicate1(head);
	// removedulicate2(head);
	print(head);
	return 0;
}
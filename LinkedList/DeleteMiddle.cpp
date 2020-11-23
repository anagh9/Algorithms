/*
 Implement an algorithm to delete a node in the middle of a single linked list, given
 only access to that node. EXAMPLE Input: the node ‘c’ from the linked list
 a->b->c->d->e Result: nothing is returned, but the new linked list looks like a->b->d->e
*/

/*
The key to this problem is that you only have one pointer to the node to be deleted. If you delete it directly, the linked list will be broken. But you can't get the pointer of the node before that node. Yes, it doesn't even
provide the head node. In this case, you can only find another way. Re-examining this problem, we can only get the pointer after
the c node. If you are asked to delete a certain node after the c node, then it must be no problem. For example, to delete node d, you only need to point the next pointer of c to e, and then delete d is OK. Okay, if we delete node d, we will get a->b->c->e, which is only one node away from the target list. How to do it? Give the data of d to c! The structure of the node is the same, and everyone is the same to delete. The most important thing is the data in the node. As long as we leave the data a->b->d->e, it will be OK.
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

typedef struct node {
	int data;
	node *next;
} node;

node* init(int a[], int n) {
	node*head, *p;
	for (int i = 0; i < n; i++) {
		node*nd = new node();
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

bool remove(node *c) {
	if (c == NULL || c->next == NULL) return false;
	node *q = c->next;
	c ->data = q ->data;
	c ->next = q ->next;
	delete q;
	return true;
}

void print(node *head) {
	while (head) {
		cout << head -> data << " ";
		head = head ->next;
	}
	cout << endl;
}

int main() {
	int n = 10;
	int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	node* head = init(a, n);
	int cc = 3;
	node*c = head;
	for (int i = 1; i < cc; i++) c = c->next;
	print(head);
	if (remove(c))
		print(head);
	else
		cout << "Failure" << endl;
	return 0;
}

/*
Output :

9 8 7 6 5 4 3 2 1 0
9 8 6 5 4 3 2 1 0

*/
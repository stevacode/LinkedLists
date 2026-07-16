#include "LinkedLists.h"
#include <climits>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
}*first = NULL;

void create(int A[], int n)
{
	int i;
	struct Node* t, * last;
	first = new Node;
	first->data = A[0];
	first->next = NULL;
	last = first;
	for (i = 1; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

Node* linearSearch(Node* p, int key)
{
	while (p != NULL)
	{
		if (key == p->data)
			return p;
		p = p->next;
	}
	return NULL;
}


int main()
{
	int A[] = { 3,5,7,10,15 };
	create(A, 5);
	Node* result = linearSearch(first, 10);
	if (result != NULL)
		cout << "Element found: " << result->data << endl;
	else
		cout << "Element not found" << endl;
	return 0;
}
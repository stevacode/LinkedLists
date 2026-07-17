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

int count(struct Node* p)
{
	int l = 0;
	while (p != NULL)
	{
		l++;
		p = p->next;
	}
	return l;
}

void display(struct Node* p)
{
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

void sortedInsert(Node* p, int x)
{
	Node* t, * q = NULL;
	t = new Node;
	t->data = x;
	t->next = NULL;
	if (first == NULL) // If the list is empty
	{
		first = t;
		return;
	}
	while (p && p->data < x)
	{
		q = p;
		p = p->next;
	}
	if (p == first) // Insert at the beginning
	{
		t->next = first;
		first = t;
	}
	else // Insert in between or at the end
	{
		t->next = q->next;
		q->next = t;
	}
}

int main()
{
	int A[] = { 3,5,7,10,15 }; 
	create(A, 5);
	display(first);
	cout << endl;
	sortedInsert(first, 8);
	display(first);
	cout << endl;
	sortedInsert(first, 1);
	display(first);
	cout << endl;
	sortedInsert(first, 12);
	display(first);
	cout << endl;
	return 0;
}
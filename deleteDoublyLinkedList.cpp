#include "LinkedLists.h"
using namespace std;

struct Node
{
	Node* prev;
	int data;
	Node* next;
}*first = NULL;

void create(int A[], int n)
{
	int i;
	struct Node* t, * last;
	first = new Node;
	first->data = A[0];
	first->prev = NULL;
	first->next = NULL;
	last = first;
	for (i = 1; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->prev = last;
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

void display(struct Node* p)
{
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int length(struct Node* p)
{
	int len = 0;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

void insert(struct Node* p, int index, int x)
{
	struct Node* t;
	int i;
	if (index < 0 || index > length(p))
		return;
	if (index == 0)
	{
		t = new Node;
		t->data = x;
		t->prev = NULL;
		t->next = first;
		if (first)
			first->prev = t;
		first = t;
	}
	else
	{
		for (i = 0; i < index - 1; i++)
			p = p->next;
		t = new Node;
		t->data = x;
		t->prev = p;
		t->next = p->next;
		if (p->next)
			p->next->prev = t;
		p->next = t;
	}
}

int deleteNode(struct Node* p, int index)
{
	int x = -1;
	if (index < 1 || index > length(p))
		return -1;
	if (index == 1)
	{
		x = first->data;
		first = first->next;
		if (first)
			first->prev = NULL;
		delete p;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
			p = p->next;
		p->prev->next = p->next;
		if (p->next)
			p->next->prev = p->prev;
		x = p->data;
		delete p;
	}
	return x;
}

int main()
{
	int A[] = { 1, 2, 3, 4, 5 };
	create(A, 5);
	display(first);
	cout << "Length: " << length(first) << endl;

	insert(first, 0, 0); // Insert 0 at the beginning
	display(first);
	cout << "Length: " << length(first) << endl;

	insert(first, 3, 10); // Insert 10 at index 3
	display(first);
	cout << "Length: " << length(first) << endl;

	insert(first, length(first), 6); // Insert 6 at the end
	display(first);
	cout << "Length: " << length(first) << endl;

	cout << endl;

	deleteNode(first, 1); // Delete node at index 1
	display(first);
	cout << "Length: " << length(first) << endl;

	deleteNode(first, 3); // Delete node at index 3
	display(first);
	cout << "Length: " << length(first) << endl;

	deleteNode(first, length(first)); // Delete node at the end
	display(first);
	cout << "Length: " << length(first) << endl;

	return 0;
}
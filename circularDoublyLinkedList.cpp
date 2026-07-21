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
	last->next = first;
	first->prev = last;
}

void display(struct Node* p)
{
	if (p == NULL) return;
	do {
		cout << p->data << " ";
		p = p->next;
	} while (p != first);
	cout << endl;
}

int length(struct Node* p)
{
	int len = 0;
	if (p == NULL) return len;
	do {
		len++;
		p = p->next;
	} while (p != first);
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
		if (first == NULL)
		{
			first = t;
			first->next = first;
			first->prev = first;
		}
		else
		{
			t->next = first;
			t->prev = first->prev;
			first->prev->next = t;
			first->prev = t;
			first = t;
		}
	}
}

int deleteNode(struct Node* p, int index)
{
	int x = -1;
	struct Node* q;
	int i;
	if (index < 1 || index > length(p))
		return -1;
	if (index == 1)
	{
		q = first;
		x = first->data;
		if (first->next == first) // Only one node
		{
			delete first;
			first = NULL;
		}
		else
		{
			first->prev->next = first->next;
			first->next->prev = first->prev;
			first = first->next;
			delete q;
		}
	}
	else
	{
		for (i = 0; i < index - 1; i++)
			p = p->next;
		q = p;
		x = p->data;
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete q;
	}
	return x;
}

void reverse(struct Node* p)
{
	if (p == NULL) return;
	Node* temp = NULL;
	Node* current = p;
	do {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev; // Move to the next node in the original order
	} while (current != p);
	first = temp->prev; // Update first to the new head of the list
}

int main()
{ 
	int A[] = { 1,2,3,4,5 };
	int n = sizeof(A) / sizeof(A[0]);
	create(A, n);
	display(first);
	reverse(first);
	display(first);

	insert(first, 0, 0);
	display(first);
	cout << "Length: " << length(first) << endl;
	deleteNode(first, 1);
	display(first);
	cout << "Length: " << length(first) << endl;
	
	return 0;
}
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

void deleteNode(Node* p, int index)
{
	Node* q = NULL;
	int x = -1;
	if (index < 1 || index > count(p))
		return;
	if (index == 1)
	{
		q = first;
		x = first->data;
		first = first->next;
		delete q;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		delete p;
	}
	cout << "Deleted element: " << x << endl;
}

int main()
{
	int A[] = { 3,5,7,10,15 }; 
	create(A, 5);
	display(first);
	cout << endl;
	deleteNode(first, 3);
	display(first);
	cout << endl;
	deleteNode(first, 1);
	display(first);
	cout << endl;
	deleteNode(first, 4);
	display(first);
	cout << endl;
	return 0;
}
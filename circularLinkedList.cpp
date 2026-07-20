#include "LinkedLists.h"
using namespace std;

struct Node
{
	int data;
	struct Node* next;
}*Head;

void create(int A[], int n)
{
	int i;
	struct Node* t, * last;
	Head = new Node;
	Head->data = A[0];
	Head->next = Head;
	last = Head;
	for (i = 1; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = last->next;
		last->next = t;
		last = t;
	}
}

void display(Node* h)
{
	do
	{
		cout << h->data << " ";
		h = h->next;
	} while (h != Head);
	cout << endl;
}

void recursiveDisplay(Node* h)
{
	static int flag = 0;
	if (h != Head || flag == 0)
	{
		flag = 1;
		cout << h->data << " ";
		recursiveDisplay(h->next);
	}
	flag = 0;
}

int length(Node* h)
{
	int len = 0;
	do
	{
		len++;
		h = h->next;
	} while (h != Head);
	return len;
}

void insert(Node* p, int index, int x)
{
	Node* t;
	if (index < 0 || index > length(Head))
		return;
	t = new Node;
	t->data = x;
	if (index == 0)
	{
		if (Head == NULL)
		{
			Head = t;
			Head->next = Head;
		}
		else
		{
			while (p->next != Head)
				p = p->next;
			p->next = t;
			t->next = Head;
			Head = t;
		}
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
			p = p->next;
		t->next = p->next;
		p->next = t;
	}
}

int Delete(Node* p, int index)
{
	Node* q;
	int x = -1;
	if (index < 1 || index > length(Head))
		return -1;
	if (index == 1)
	{
		while (p->next != Head)
			p = p->next;
		x = Head->data;
		if (Head == p) // if only one node in the list
		{
			delete Head;
			Head = NULL;
		}
		else
		{
			p->next = Head->next;
			delete Head;
			Head = p->next;
		}
	}
	else
	{
		for (int i = 0; i < index - 2; i++)
			p = p->next;
		q = p->next;
		p->next = q->next;
		x = q->data;
		delete q;
	}
	return x;
}

int main()
{
	int A[] = { 1, 2, 3, 4, 5 , 6};
	create(A, 6);
	display(Head);
	recursiveDisplay(Head);
	cout << endl;
	insert(Head, 0, 10);
	display(Head);
	insert(Head, 3, 11);
	display(Head);
	insert(Head, 8, 12);
	display(Head);
	cout << "Deleted element: " << Delete(Head, 1) << endl;
	display(Head);
	return 0;
}
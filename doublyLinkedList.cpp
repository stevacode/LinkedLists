#include "LinkedLists.h"
using namespace std;

struct Node
{
	Node* prev;
	int data;
	Node* next;
}*first=NULL;

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



int main()
{
	int A[] = { 1, 2, 3, 4, 5 }; 
	create(A, 5);
	display(first);
	cout << "Length: " << length(first) << endl;

	return 0;
}
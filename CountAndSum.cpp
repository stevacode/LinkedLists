#include "LinkedLists.h"
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

void display(struct Node* p)
{
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
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

int sum(struct Node* p)
{
	int s = 0;
	while (p != NULL)
	{
		s += p->data;
		p = p->next;
	}
	return s;
}

int main()
{
	int A[] = { 3,5,7,10,15 };
	create(A, 5);
	display(first);
	cout << "Count: " << count(first) << endl;
	cout << "Sum: " << sum(first) << endl;

	return 0;
}
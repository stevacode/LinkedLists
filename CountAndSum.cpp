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

int recursiveCount(struct Node* p)
{
	if (p != NULL)
		return recursiveCount(p->next) + 1;
	else
		return 0;
}

int count2(Node* p)
{
	int x = 0;
	if (p)
	{
		x = count2(p->next);
		return x + 1;
	}
	else
		return 0;
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

int recursiveSum(struct Node* p)
{
	if (p == NULL)
		return 0;
	else
		return recursiveSum(p->next) + p->data;
}

int main()
{
	int A[] = { 3,5,7,10,15 };
	create(A, 5);
	display(first);
	cout << endl;
	cout << "Count: " << count(first) << endl;
	cout << "Sum: " << sum(first) << endl;
	cout << "Recursive Count: " << recursiveCount(first) << endl;
	cout << "Recursive Sum: " << recursiveSum(first) << endl;
	cout << "Count2: " << count2(first) << endl;

	return 0;
}
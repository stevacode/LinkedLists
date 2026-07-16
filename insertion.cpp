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

void insert(Node* p, int index, int x)
{
	Node* t;
	if (index < 0 || index > count(p))
		return;
	t = new Node;
	t->data = x;
	if (index == 0)
	{
		t->next = first;
		first = t;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
			p = p->next;
		t->next = p->next;
		p->next = t;
	}
}

int main()
{
	//int A[] = { 3,5,7,10,15 };
	//create(A, 5);
	//display(first);
	//cout << endl;
	//insert(first, 0, 10);
	//display(first);
	//cout << endl;
	//insert(first, 3, 10);
	//display(first);
	//cout << endl;
	////invalid index
	//insert(first, 8, 10);
	//display(first);
	//cout << endl;
	//using insert function to insert various nodes at different positions
	insert(first, 0, 1);
	display(first);
	cout << endl;
	insert(first, 1, 2);
	display(first);
	cout << endl;
	insert(first, 2, 3);
	display(first);
	cout << endl;




	return 0;
}
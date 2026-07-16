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

void display(struct Node* p)
{
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
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

Node* recursiveLinearSearch(Node* p, int key)
{
	if (p == NULL)
		return NULL;
	if (key == p->data)
		return p;
	return recursiveLinearSearch(p->next, key);
}

//move to front linear search
Node* moveToFrontLinearSearch(Node* p, int key)
{
	Node* q = NULL;
	while (p != NULL)
	{
		if (key == p->data)
		{
			if (q != NULL)
			{
				q->next = p->next;
				p->next = first;
				first = p;
			}
			return p;
		}
		q = p;
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
		cout << "\nElement found: " << result->data << endl;
	else
		cout << "\nElement not found" << endl;

	//Testing recursive linear search
	result = recursiveLinearSearch(first, 20);
	if (result != NULL)
		cout << "\nElement found: " << result->data << endl;
	else
		cout << "\nElement not found" << endl;

	//Testing move to front linear search
	result = moveToFrontLinearSearch(first, 7);
	if (result != NULL)
		cout << "\nElement found: " << result->data << endl;
	else
		cout << "\nElement not found" << endl;
	display(first);


	result = moveToFrontLinearSearch(first, 15);
	if (result != NULL)
		cout << "\nElement found: " << result->data << endl;
	else
		cout << "\nElement not found" << endl;
	display(first);

	result = moveToFrontLinearSearch(first, 10);
	if (result != NULL)
		cout << "\nElement found: " << result->data << endl;
	else
		cout << "\nElement not found" << endl;
	display(first);
	return 0;
}
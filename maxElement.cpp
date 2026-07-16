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

int max(Node* p){
	int max = INT_MIN;
	while (p)
	{
		if (p->data > max)
			max = p->data;
		p = p->next;
	}
	return max;
}

int min(Node* p) {
	int min = INT_MAX;
	while (p)
	{
		if (p->data < min)
			min = p->data;
		p = p->next;
	}
	return min;
}

int recursiveMax(Node* p) {
	if (p == NULL)
		return INT_MIN;
	int x = recursiveMax(p->next);
	return (x > p->data) ? x : p->data;
}

int recursiveMin(Node* p) {
	if (p == NULL)
		return INT_MAX;
	int x = recursiveMin(p->next);
	return (x < p->data) ? x : p->data;
}

int main()
{
	int A[] = { 3,5,7,10,15 };
	create(A, 5);
	display(first);
	cout << endl;
	cout << "Max Element: " << max(first) << endl;
	cout << "Min Element: " << min(first) << endl;
	cout << "Recursive Max Element: " << recursiveMax(first) << endl;
	cout << "Recursive Min Element: " << recursiveMin(first) << endl;
	return 0;
}
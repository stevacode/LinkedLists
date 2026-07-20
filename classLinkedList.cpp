#include "LinkedLists.h"
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class LinkedList
{
private:
	Node* first;
public:
	LinkedList() { first = NULL; }
	LinkedList(int A[], int n);
	~LinkedList();
	void Display();
	void Insert(int index, int x);
	int Delete(int index);
	int Length();
};

LinkedList::LinkedList(int A[], int n)
{
	Node* last, * t;
	int i = 0;
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
LinkedList::~LinkedList()
{
	Node* p = first;
	while (first)
	{
		first = first->next;
		delete p;
		p = first;
	}
}
void LinkedList::Display()
{
	Node* p = first;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void LinkedList::Insert(int index, int x)
{
	Node* t, * p = first;
	if (index < 0 || index > Length())
		return;
	t = new Node;
	t->data = x;
	t->next = NULL;
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

int LinkedList::Delete(int index)
{
	Node* p = first, * q = NULL;
	int x = -1;
	if (index < 1 || index > Length())
		return -1;
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
	return x;
}

int LinkedList::Length()
{
	int length = 0;
	Node* p = first;
	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}

int main()
{
	int A[] = { 3,5,7,10,15 };
	LinkedList l(A, 5);
	l.Display();
	cout << "Length: " << l.Length() << endl;
	l.Insert(0, 2);
	l.Display();
	cout << "Length: " << l.Length() << endl;
	cout << "Deleted Element: " << l.Delete(3) << endl;
	
	l.Display();
	cout << "Length: " << l.Length() << endl;

	return 0;
}
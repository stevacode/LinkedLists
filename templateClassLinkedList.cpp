#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node<T>* next;
};

template <class T>
class LinkedList
{
private:
	Node<T>* first;
public:
	LinkedList() { first = NULL; }
	LinkedList(T A[], int n);
	~LinkedList();
	void Display();
	void Insert(int index, T x);
	T Delete(int index);
	int Length();
};

template <class T>
LinkedList<T>::LinkedList(T A[], int n)
{
	Node<T>* last, * t;
	int i = 0;
	first = new Node<T>;
	first->data = A[0];
	first->next = NULL;
	last = first;
	for (i = 1; i < n; i++)
	{
		t = new Node<T>;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* p = first;
	while (first)
	{
		first = first->next;
		delete p;
		p = first;
	}
}

template <class T>
void LinkedList<T>::Display()
{
	Node<T>* p = first;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template <class T>
void LinkedList<T>::Insert(int index, T x)
{
	Node<T>* t, * p = first;
	if (index < 0 || index > Length())
		return;
	t = new Node<T>;
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

template <class T>
T LinkedList<T>::Delete(int index)
{
	Node<T>* p = first, * q = NULL;
	T x = T();
	if (index < 1 || index > Length())
		return T();
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

template <class T>
int LinkedList<T>::Length()
{
	int length = 0;
	Node<T>* p = first;
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
	LinkedList<int> l(A, 5);
	l.Display();
	cout << "Length: " << l.Length() << endl;
	l.Insert(0, 2);
	l.Display();
	cout << "Length: " << l.Length() << endl;
	cout << "Deleted Element: " << l.Delete(3) << endl;

	l.Display();
	cout << "Length: " << l.Length() << endl;

	double B[] = { 1.5, 2.5, 3.5 };
	LinkedList<double> d(B, 3);
	d.Display();
	cout << "Length: " << d.Length() << endl;
	d.Insert(1, 4.5);
	d.Display();
	cout << "Length: " << d.Length() << endl;
	cout << "Deleted Element: " << d.Delete(2) << endl;
	d.Display();
	cout << "Length: " << d.Length() << endl;

	return 0;
}
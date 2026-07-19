#include "LinkedLists.h"
#include <climits>   // nije korišćen u ovom fajlu
using namespace std;

struct Node
{
	int data;
	struct Node* next;
}*first = NULL;   // globalna glava liste — sve funkcije je menjaju direktno

void create(int A[], int n)
{
	int i;
	struct Node* t, * last;
	first = new Node;          // prvi čvor posebno, jer nema prethodnika
	first->data = A[0];        // pažnja: ako je n <= 0, ovo je čitanje van niza
	first->next = NULL;
	last = first;              // last uvek pokazuje na poslednji čvor
	for (i = 1; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = NULL;
		last->next = t;        // zakači novi čvor na kraj
		last = t;              // pomeri kraj
	}
}

int count(struct Node* p)
{
	int l = 0;
	while (p != NULL)          // p je kopija — menjanje ne kvari listu
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
	// napomena: nema endl na kraju — pozivalac mora sam da ga doda,
	// inače se dva uzastopna ispisa spoje u isti red
}

// ---------- 1) ITERATIVNO ----------
// Tri pokazivača kližu kroz listu; u svakom koraku okrene se jedna veza unazad.
void reverseList1(struct Node* p)
{
	Node* q = NULL;            // q = trenutni (posle prve dodele)
	Node* r = NULL;            // r = prethodni
	while (p != NULL)
	{
		r = q;                 // stari trenutni postaje prethodni
		q = p;                 // p postaje trenutni
		p = p->next;           // KLJUČNO: pomeri p PRE nego što pregaziš q->next,
		// inače gubiš referencu na ostatak liste
		q->next = r;           // okreni vezu unazad
	}
	first = q;                 // po izlasku p je NULL, a q je poslednji čvor = nova glava
}

// ---------- 2) REKURZIVNO ----------
// q = prethodni, p = trenutni. Veze se okreću NA POVRATKU iz rekurzije,
// dakle od repa ka glavi.
void reverseList2(Node* q, Node* p)
{
	if (p != NULL)
	{
		reverseList2(p, p->next);  // prvo siđi do dna; p napreduje na p->next
		p->next = q;               // tek na povratku okreni vezu
	}
	else
		first = q;                 // dno rekurzije: q je poslednji čvor = nova glava
	// poziv bi bio: reverseList2(NULL, first);
	// u main-u se ne poziva
}

// ---------- 3) PREKO NIZA ----------
// Suštinski drugačije: veze se NE diraju, menja se samo sadržaj (data).
// Zato first ostaje isti čvor. Cena: O(n) dodatne memorije.
void reverseList3(Node* p)
{
	int* A, i = 0;
	Node* q = p;
	A = new int[count(p)];     // count() je dodatni prolaz kroz listu
	while (q != NULL)          // prvi prolaz: prepiši vrednosti u niz
	{
		A[i++] = q->data;
		q = q->next;
	}
	q = p;
	i--;                       // posle petlje i == n, pa vrati na poslednji validan indeks
	while (q != NULL)          // drugi prolaz: upiši nazad obrnutim redom
	{
		q->data = A[i--];      // A[i--] već dekrementira i — NE dodavati još jedan i--
		q = q->next;
	}
	delete[] A;
}

// ---------- 4) ISPIS UNAZAD ----------
// Ime vara: ovo NIJE obrtanje. Lista ostaje potpuno nepromenjena.
// Ispis je posle rekurzivnog poziva, pa se dešava na povratku = od repa ka glavi.
void reverseList4(Node* p)
{
	if (p != NULL)
	{
		reverseList4(p->next);
		cout << p->data << " ";
	}
}

// ---------- 5) GREŠKA ----------
void reverseList5(Node* p, Node* q)
{
	if (p)
	{
		reverseList5(p, p->next);  // BUG: prvi argument je i dalje p, ne p->next.
		// p se nikad ne približi NULL -> beskonačna rekurzija.
		// Treba: reverseList5(p->next, p);
		p->next = q;
	}
	else
	{
		first = q;
	}
}

int main()
{
	int A[] = { 3,5,7,10,15 };
	create(A, 5);
	display(first);
	cout << endl;              // 3 5 7 10 15

	reverseList1(first);       // stvarno obrće veze
	display(first);
	cout << endl;              // 15 10 7 5 3

	reverseList3(first);       // obrće data, vraća na početno stanje
	display(first);
	cout << endl;              // 3 5 7 10 15

	reverseList4(first);       // SAMO ISPISUJE 15 10 7 5 3
	display(first);            // nedostaje endl iznad -> ova dva ispisa se SPOJE u jedan red
	cout << endl;              // 15 10 7 5 3 3 5 7 10 15

	reverseList5(NULL, first); // p je NULL -> odmah else -> first = first.
	// Rekurzivna grana se nikad ne izvrši. NIŠTA se ne desi.
	display(first);
	cout << endl;              // 3 5 7 10 15 — identično prethodnom stanju
	cout << endl;

	// nema oslobađanja memorije: nijedan new Node se ne brise (delete)
	return 0;
}
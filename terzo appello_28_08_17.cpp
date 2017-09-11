// TERZO APPELLO 2017
//
// Traccia:
// https://elearning.studenti.math.unipd.it/labs/pluginfile.php/5834/mod_vpl/intro/testo-28-8-2017-T1.pdf

#include<iostream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a =0, nodo* b=0){info=a; next=b;}};
struct doppioN{nodo*inizio,* fine; int lung; doppioN(nodo* a =0, nodo* b=0, int c=0){inizio=a; fine=b;lung=c;}};

nodo* build(int n)
{
	if(n>0)
	{
		int x;
		cin>>x;
		return new nodo(x,build(n-1));
	}
	else
		return 0;
}

void stampa_DN(doppioN A)
{
	cout<<"valore DN:"<<A.inizio->info<<' '<<A.fine->info<<" lung="<<A.lung<<endl;
}

void stampaL(nodo*L)
{
	if(L)
	{
		cout<<L->info<<' ';
		stampaL(L->next);
	}
	else
		cout<<endl;
	
}

nodo*clone(nodo*L)
{
	if(L)
		return new nodo(L->info,clone(L->next));
	else
		return 0;
}

doppioN Fiter(nodo*L) {
	doppioN result;
	result.inizio = result.fine = L;
	result.lung = 1;
	
	while(L->next) {
		int lung = 1;
		nodo* T = L;
		
		while (T->next && T->next->info >= T->info) {
			lung++;
			T = T->next;
		}
		
		if (lung > result.lung) {
			result.lung = lung;
			result.inizio = L;
			result.fine = T;
		}
		
		L = L->next;
	}
	
	return result;
}

doppioN Aux(nodo*L) {
	if (!L->next || L->next->info < L->info) {
		doppioN end;
		end.inizio = end.fine = L;
		end.lung = 1;
		return end;
	}
	
	doppioN result;
	result.inizio = L;
	doppioN ric = Aux(L->next);
	result.lung = 1 + ric.lung;
	result.fine = ric.fine;
	
	return result;
}

doppioN Frec(nodo*L) {
	if (!L->next) {
		doppioN z;
		z.inizio = z.fine = L;
		z.lung = 1;
		return z;
	}
	
	doppioN result = Aux(L);
	
	doppioN ric = Frec(L->next);
	if (result.lung < ric.lung) {
		result = ric;
	}
	
	return result;
}

nodo* Giter(nodo*& L, doppioN  A) {
	bool stop = false;
	nodo* T = L;
	
	if (L == A.inizio)
		L = A.fine->next;
	else {
		while (T->next != A.inizio)
			T = T->next;
		
		T->next = A.fine->next;
	}
	
	A.fine->next = 0;
	return A.inizio;
}

nodo* Grec(nodo*& L, doppioN  A) {
	if (L == A.inizio) {
		L = A.fine->next;
		A.fine->next = 0;
		return A.inizio;
	}
	
	Grec(L->next, A);
}

int main()
{
	int n;
	cin>>  n;
	cout<<"start"<<endl;
	nodo*L=build(n);
	stampaL(L);
	
	nodo* L1=clone(L);
	doppioN A=Fiter(L);//da fare
	doppioN B=Frec(L1);//da fare
	stampa_DN(A);
	stampa_DN(B);
	nodo*K=Giter(L,A);//da fare
	nodo*K1=Grec(L1,B); //da fare
	stampaL(K);
	stampaL(L);
	stampaL(K1);
	stampaL(L1);
	cout<<"end"<<endl;
}

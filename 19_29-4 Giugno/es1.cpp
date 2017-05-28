#include<iostream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct doppialista{nodo* listamatch, * restante; doppialista(nodo*a=0, nodo* b=0){listamatch=a; restante=b;}};

nodo* crea(int dim)
{
    if(dim)
    {
        int x;
        cin>>x;
        return new nodo(x,crea(dim-1));
    }
    return 0;
}

void stampa(nodo*L)
{
    if(L)
    {
        cout<<L->info<<' ';
        stampa(L->next);
    }
    else
        cout<<endl;
}

void leggi(int dim, int*P)
{
    if(dim)
    {
        cin>>*P;
        leggi(dim-1,P+1);
    }
}

doppialista* match2 (nodo* T, int* P, int dimP) {
	if (!T) return NULL;
	
	if (T -> info == *P) {
	    if (dimP == 1)
			    return new doppialista(new nodo(*P), T->next);
	    else {
		    doppialista *x = match2(T->next, P + 1, dimP - 1);
		    if (x) return new doppialista(new nodo(T->info, x->listamatch), x->restante);
	    }
	}
	else {
		doppialista *k = match2(T->next, P, dimP);
		if (k) return new doppialista(k->listamatch, new nodo(T->info, k->restante));
	}
}

int main()
{
    int dim, dimP, P[20];
    cin>>dim;
    nodo* L1=crea(dim);
    cin>>dimP;
    leggi(dimP, P);
    cout<<"start"<<endl;
    doppialista* D= match2(L1, P, dimP);
    if(!D)
    {
        cout<<"no match"<<endl;
        cout<<"Lista T e':";
        stampa(L1);
    }
    else
    {
        stampa(D->listamatch);
        if(D->restante)
            stampa(D->restante);
        else
            cout<<"Lista restante vuota"<<endl;
    }
    cout<<"end"<<endl;
}

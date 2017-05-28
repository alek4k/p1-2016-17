#include<iostream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

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

nodo* match(nodo* &n, int*P, int dimP) {
    if (!n) return NULL;
 
	if (n -> info == *P) {
        if (dimP == 1) {
            n = n -> next;
            return new nodo(*P);
        }
        else {
            nodo *x = match(n->next, P + 1, dimP - 1);
            if (x) {
                int temp = n -> info;
                n = n -> next;
    
                return new nodo(temp, x);
            }
        }
	}
	else match(n -> next, P, dimP);
}

main()
{
  int dim, dimP, P[20];
  cin>>dim;
  nodo* L1=crea(dim);
  cin>>dimP;
  leggi(dimP, P);
  cout<<"start"<<endl;
  nodo* L2= match(L1,P, dimP);
  if(L2)
    stampa(L2);
  else
    cout<<"Lista del match vuota"<<endl;
   if(L1)
     stampa(L1);
   else
     cout<<"Lista restante vuota"<<endl;
   cout<<"end"<<endl;
}

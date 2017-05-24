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

void leggi(int dim, int*P)
{
  if(dim)
   {
    cin>>*P;
    leggi(dim-1,P+1);
   }
}

bool findMatch (nodo *n, int*P, int dimP) {
    if (!n)
        return false;
    
    if (n -> info == *P) {
        if (dimP == 1) return true;
        else findMatch (n -> next, P + 1, dimP - 1);
    }
    else return false;
}

void saveMatch (nodo* &L, int *P, int dimP) {
    if(!dimP)
        return;
    else if(!L)
        L = new nodo(*P);
    
    saveMatch (L -> next, P + 1, dimP - 1);
}

void skipList (nodo* &L, int dimP) {
    if(!dimP)
        return;
    
    L = L -> next;
    skipList (L, dimP - 1);
}

nodo* match(nodo* &n, int*P, int dimP) {
    if (!n || !dimP) return 0;
    
    if (findMatch(n, P, dimP)) {
        nodo*temp = NULL;
        saveMatch(temp, P, dimP);
        skipList(n, dimP);
        return temp;
    }
    else match(n -> next, P, dimP);
}

void stampa (nodo * L) {
    if (!L) {
        cout << endl;
        return;
    }
    cout << L->info << " ";
    stampa (L->next);
}

main()
{
  int dim, dimP, P[20];
  cout<<"start"<<endl;
  cin>>dim;
  nodo* L1=crea(dim);
  cin>>dimP;
  leggi(dimP, P);
  nodo* L2= match(L1, P, dimP);//da fare
  stampa(L2); //da fare
  stampa(L1);
  cout<<"end"<<endl;
}

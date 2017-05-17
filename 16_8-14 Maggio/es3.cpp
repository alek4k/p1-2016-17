#include<iostream>
using namespace std;

struct nodo {
    int info;
    nodo* next;
    
    nodo (int value = 0, nodo * L = 0) {
        next = L;
        info = value;
    }
};

nodo* trova(int*L,int n, int e);
bool trova_lab (int*L, int dim, int i, int j, nodo * &head);
void stampa(nodo*head, int n, int c);

main()
{
  int n;
  cin>>n;
  int* L= new int [n*n];
  for(int i=0; i<n*n; i++)
          cin>>L[i];
  nodo* x=trova(L,n,0);//da fare
  cout<<"start"<<endl;
  if(x)
    { cout<<"il cammino e':"; stampa(x,n,0);}//da fare
    
  else
    cout<<"il cammino non esiste"<<endl;
  cout<<"end"<<endl;
      
}

nodo * addNode (int value, nodo *L) {
    if (!L)
        return new nodo (value);
    
    L->next = addNode (value, L->next);
    return L;
}

nodo * del(nodo*n) {
    if(!n -> next) {
        return 0;
    }
    n -> next = del(n -> next);
    return n; 
}

nodo * trova(int*L,int n, int e) {
    nodo *head = NULL;
    
    if (e > n - 1)
        return head;
    
    //nodo &start = *head;
    if (trova_lab (L, n, 0, e, head))
        return head;
    else
        return trova (L, n, e + 1);
}

bool trova_lab (int*L, int dim, int i, int j, nodo * &head) {
    if (*(L + (i*dim) + j) == 0 || j < 0 || j > dim - 1) {
        if (head)
            head = del(head);
        return false;
    }
    else
        head = addNode(j, head);
    if (i == dim - 1)
        return true;
    
    return trova_lab(L, dim, i + 1, j - 1, head->next) || trova_lab(L, dim, i + 1, j, head->next) || trova_lab(L, dim, i + 1, j + 1, head->next);
}

void stampa(nodo*head, int n, int c) {
    if (c == n) {
        cout << endl;
        return;
    }
        
    cout << "(" << c << "," << head->info << ") ";
    stampa (head->next, n, c + 1);
}

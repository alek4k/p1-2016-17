#include<iostream>
using namespace std;

struct nodo{int num, info; nodo* next; nodo(int a=0,int b=0, nodo* c=0){num=a; info=b; next=c;}}; // nodo di lista
struct FIFO{nodo* primo, *ultimo; FIFO(nodo*a=0, nodo*b=0){primo=a; ultimo=b;}};
struct nodoF{FIFO info; nodoF*next; nodoF(FIFO a=FIFO(),nodoF*b=0){info=a; next=b;}}; //nodo di lista con FIFO

FIFO push_end(FIFO a, nodo*b)
{
    b->next=0;
    if(!a.primo)
    {a.primo=a.ultimo=b;}
    else
    {a.ultimo->next=b; a.ultimo=b;}
    return a;
}

FIFO push_begin(FIFO a, nodo* b)
{
    if(!a.primo)
    {a.primo=a.ultimo=b; b->next=0; return a;}
    else
    {
        b->next=a.primo;
        a.primo=b;
        return a;
    }
}

void stampa_L(nodo*L)
{
    if (L)
    {cout<<'['<<L->num<<','<<L->info<<']'<<' '; stampa_L(L->next);}
    else
        cout<<endl;

}

void stampa_F(nodoF* x)
{
    if(x)
    {
        stampa_L(x->info.primo);
        cout<<endl;
        stampa_F(x->next);
    }
}

nodo* costruisci(int n, int dim)
{
    if(dim)
    {int x; cin>>x; return new nodo(n,x,costruisci(n+1,dim-1));}
    return 0;
}

nodo* clone(nodo*a)
{
    if(a)
    {return new nodo(a->num, a->info, clone(a->next));}
    return 0;
}

FIFO eliminaR (nodo*&L, int x) {
    if (!L) return FIFO();

    if (L->info == x) {
        nodo* temp = L;
        L = L->next;
        return push_begin(eliminaR(L, x), temp);
    }
    else {
        eliminaR(L->next, x);
    }
}

FIFO eliminaR_alternativa(nodo*&L, int x) {
    if (!L) return FIFO();

    FIFO b = eliminaR_alternativa(L->next,x);
    if (L->info == x) {
        nodo*temp = L;
        L = L->next;
        b = push_begin(b, temp);
    }

    return b;
}

nodoF* insR(nodoF*Q, FIFO x) { //ricorsiva
    if (!Q) return new nodoF(x);

    if (Q->info.primo->info > x.primo->info) {
        return new nodoF(x, Q);
    }
    Q->next = insR(Q->next, x);

    return Q;
}

nodoF* tieni_primo_ric(nodo*& L) {
    if(!L) return NULL;

    FIFO a = eliminaR(L->next, L->info);
    nodoF* b = tieni_primo_ric(L->next);
    if (a.primo) b = insR(b, a);

    return b;
}

nodoF* insI(nodoF*Q,FIFO x) { //iterativa
    if(!Q || x.primo->info < Q->info.primo->info) {
        return new nodoF(x, Q);
    }

    nodoF* result = Q;

    while (Q->next && Q->next->info.primo->info < x.primo->info) {
        Q = Q->next;
    }

    Q->next = new nodoF(x, Q->next);

    return result;
}

nodoF* tieni_primo_iter(nodo*& L){
    nodoF* result = 0;
    nodo* scorri = L;

    while (scorri){
        FIFO a = eliminaR(scorri->next, scorri->info);
        if (a.primo) result = insI (result, a);
        scorri = scorri->next;
    }

    return result;
}

int main ()
{
    int dim;
    cout<<"start"<<endl;
    cin>>dim;
    nodo*C=costruisci(0,dim);
    nodo* D=clone(C);
    cout<<"Lista costruita"<<endl;
    stampa_L(C);
    nodoF* a =tieni_primo_ric(C); //da fare
    cout<<"soluzione ricorsiva"<<endl<<"nodi tolti:"<<endl;

    stampa_F(a);
    cout<<"lista rimanente:"<<endl;
    stampa_L(C);
    nodoF* b=tieni_primo_iter(D); //da fare
    cout<<"soluzione iterativa"<<endl<<"nodi tolti:"<<endl;
    stampa_F(b);
    cout<<"lista rimanente:"<<endl;
    stampa_L(D);
    cout<<"end";
}

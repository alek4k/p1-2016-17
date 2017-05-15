#include <iostream>

using namespace std;

struct nodo {
    int chiave;
    nodo *next;
    
    nodo (nodo *L, int value) {
        next = L;
        chiave = value;
    }
};

// PRE = (L = L_0, L_1, ... è una lista di interi)
int cerca(int k, nodo *L);
// POST = (ritorna il più piccolo indice i tale che L_i.chiave == k, oppure -1 se non esiste)
nodo * addNode (nodo *L, int value);

int main() 
{
    cout << "start" << endl;
    
    nodo *head = NULL;
    int n;
    cin >> n;
    while (n != -1) {
        head = addNode (head, n);
        cin >> n;
    }
    
    int k;
    cin >> k;
    if (!head)
        cout << "Il valore " << k << " non si trova nella lista" << endl;
    else {
        int a = cerca (k, head);
        if (a == -1)
            cout << "Il valore " << k << " non si trova nella lista" << endl;
        else
            cout << "Il valore " << k << " si trova in posizione " << a << endl;
    }

    cout << "end" << endl;
}

int cerca (int k, nodo *L) {
    if (L->chiave == k)
        return 0;
    if (L->next == NULL && L->chiave != k)
        return -1;
    
    if(1 + cerca(k, L->next) > 0)
        return 1 + cerca(k, L->next);
    else
        return -1;
}

nodo * addNode (nodo *L, int value) {
    if (!L)
        return new nodo (NULL, value);
    
    L->next = addNode (L->next, value);
    return L;
}

#include <iostream>

using namespace std;

struct nodo {
    int chiave;
    nodo *next;
    
    nodo (int value, nodo * L) {
        next = L;
        chiave = value;
    }
};

// PRE = (L è una lista ordinata in modo crescente)
nodo* inserisci_in_ordine(int k, nodo *L);
// POST = (inserisce k in L mantenendo l'ordine e ritorna la lista aggiornata)
void stampa (nodo * L);

int main() 
{
    cout << "start" << endl;
    
    nodo *head = NULL;
    int n;
    cin >> n;
    while (n != -1) {
        head = inserisci_in_ordine (n, head);
        cin >> n;
    }
    
    stampa (head);
    
    cout << "end" << endl;
}

void stampa (nodo * L) {
    if (!L) return;
    
    cout << L->chiave << " ";
    stampa (L->next);
}

nodo * inserisci_in_ordine (int k, nodo *L) {
    if (!L)
        return new nodo (k, NULL);
    else if (L->chiave > k) {
        return new nodo (k, L);
    }
    
    L->next = inserisci_in_ordine (k, L->next);
    return L;
}

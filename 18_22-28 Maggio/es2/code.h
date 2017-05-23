#include<iostream>

struct nodo {
    int chiave;
    nodo *next;
    
    nodo(int k=0, nodo* n=NULL) {chiave = k; next = n;};
};

struct coda {
    nodo *inizio;
    nodo *fine;
    
    coda(nodo *i = NULL, nodo *f = NULL) {inizio = i; fine = f;};
};

void push(int k, coda &Q);
int pop(coda &Q);
bool e_vuota(coda Q);

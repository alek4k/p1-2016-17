#include<iostream>

struct nodo {
    char chiave;
    nodo *next;
    
    nodo(char c='\0', nodo* n=NULL) {chiave = c; n = next;};
};

struct coda {
    nodo *inizio;
    nodo *fine;
    
    coda(nodo *i = NULL, nodo *f = NULL) {inizio = i; fine = f;};
};

void push(char c, coda &Q);
char pop(coda &Q);
bool e_vuota(coda Q);


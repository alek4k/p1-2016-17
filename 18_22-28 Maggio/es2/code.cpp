#include<iostream>

#include "code.h"

void push(int k, coda &Q) {
    if (e_vuota(Q)) {
        Q.inizio = new nodo(k);
        Q.fine = Q.inizio;
    }
    else {
        Q.fine -> next = new nodo (k);
        Q.fine = Q.fine -> next;
    }
}

int pop(coda &Q) {
    int result;
    
    if (!e_vuota(Q) && Q.inizio -> next) {
        result = Q.inizio -> chiave;
        Q.inizio = Q.inizio -> next;
    }
    else if (!e_vuota(Q)) {
        result = Q.inizio -> chiave;
        Q.inizio = NULL;
        Q.fine = NULL;
    }

    return result;
}

bool e_vuota(coda Q) {
    return (!Q.inizio);
}

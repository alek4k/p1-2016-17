#include<iostream>
using namespace std;

/*
-leggere in matrice con 5 colonne
-contare quante righe ci sono con seconda colonna a i=0,1,2
-considero il corridore 0,1,2,....n_part e parto dalla riga del corridore i con sensore 0
 e cerco quella con sensore 1, chiamo una funzione che mi calcoli la differenza tra i 2 orari.
 Se va bene, cerco il sensore successivo, ecc...
*/

struct orario {
    int ore, minuti, secondi;
};

struct giocatore {
    orario ora_passaggio[3];
    bool passaggio[3];
};

void controllo(giocatore* p) {
    for (int i = 0; i < 3; i++) {
        if (!(*p).passaggio[i]) throw 1;
        //oppure potevo scrivere if (!p->passaggio[i]) throw 1;
        
        if (i > 0) {
            int diff_ore = p->ora_passaggio[i].ore - p->ora_passaggio[i - 1].ore;
            int diff_minuti = p->ora_passaggio[i].minuti - p->ora_passaggio[i - 1].minuti;
            int diff_secondi = p->ora_passaggio[i].secondi - p->ora_passaggio[i - 1].secondi;
            
            int media = (diff_ore * 60 * 60 + diff_minuti * 60 + diff_secondi) / 11;
            
            if (media < 165)
                throw 2;
        }
    }
}

int main() {
    int n_part, HH, MM, SS;

    cout << "start" << endl;
    
    cin >> n_part >> HH >> MM >> SS;
    
    giocatore giocatori[n_part];
    
    bool stop = false;
    
    for (int i = 0; i < n_part; i++) {
        giocatori[i].passaggio[0] = false;
        giocatori[i].passaggio[1] = false;
        giocatori[i].passaggio[2] = false;
    }
    
    while (!stop) {
        int sensore, ore, minuti, secondi, giocatore;
      
        cin >> sensore;
      
        if ((sensore < 0) || (sensore > 2) || bool(cin) == false)
            break;
        
        cin >> giocatore >> ore >> minuti >> secondi;
        
        if (bool(cin)) {
            giocatori[giocatore].passaggio[sensore] = true;
            giocatori[giocatore].ora_passaggio[sensore].ore = ore;
            giocatori[giocatore].ora_passaggio[sensore].secondi= secondi;
            giocatori[giocatore].ora_passaggio[sensore].minuti = minuti;
        }
        else
            stop = true;
    }
    
    int errori = 0;
    for (int k = 0; k < n_part; k++) {
        try {
            controllo(giocatori + k);
            //potevo anche scrivere controllo (&giocatori[k]);
        } catch (int tipo_baro) {
            errori++;
            if (tipo_baro == 1) cout << k << ": salto sensore" << endl;
            else cout << k << ": tempo sospetto" << endl;
        }
    }
    
    if (!errori) cout << "gara regolare" << endl;
    cout << "end" << endl;
}

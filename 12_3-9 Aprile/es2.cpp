#include<iostream>
#include<stdlib.h>
using namespace std;

struct sensore {
    int * distanza;
};

struct orario {
    int ore, minuti, secondi;
};

struct giocatore {
    orario * ora_passaggio;
    bool * passaggio;
};

void controllo(giocatore* p, int n, sensore s) {
    /* PRE: p punta al giocatore corrente, n indica il numero di sensori sul percorso, s è di tipo sensore
     *      e serve per recuperare la distanza tra ogni sensore;
     *      i = 0;
     */ 
    for (int i = 0; i < n; i++) {
        /* R: (0 <= i <= n) 
         *    se il giocatore non è passato per il sensore i-esimo lancia eccezione 1;
         *    se i >= 1 -> media = (tempo passaggio sensore i - tempo passaggio sensore i-1) / (distanza tra sensore i e sensore i-1);
         *    se media < 2 min e 45 sec lancia eccezione 2;
         */ 
        if (!(*p).passaggio[i]) throw 1;
        //oppure potevo scrivere if (!p->passaggio[i]) throw 1;
        
        if (i > 0) {
            int diff_ore = p->ora_passaggio[i].ore - p->ora_passaggio[i - 1].ore;
            int diff_minuti = p->ora_passaggio[i].minuti - p->ora_passaggio[i - 1].minuti;
            int diff_secondi = p->ora_passaggio[i].secondi - p->ora_passaggio[i - 1].secondi;
            
            int media = ((diff_ore * 60 * 60 + diff_minuti * 60 + diff_secondi) / (s.distanza[i] - s.distanza[i - 1]));
            if (media < 165)
                throw 2;
        }
    }
    /* POST: (Lanciata eccezione 1 se il giocatore ha saltato un sensore)
     *       || (Lanciata eccezione 2 se il giocatore ha fatto segnare un tempo sospetto in una frazione di gara)
     *       || (i = n);
     */
     
     /* CORRETTEZZA: 1) condizione iniziale i = 0 rispettata (0 <= i <= n);
      *              2) Finchè 0 <= i < n (condizione di permanenza) eseguo il primo controllo;
      *                 Finchè 0 < i < n eseguo anche il secondo controllo (sensore < 0 non permesso);
      *              3) Se viene lanciata un' eccezione si esce dal ciclo. Verifico il caso senza eccezioni:
      *                 condizione di uscita rispettata: R && !(condizione di permanenza) => POST
      *                 infatti (0 <= i <= n) && !(0 <= i < n) ==> (0 <= i <= n) && (i >= n) => i = n (POST);
      */
}

int main() {
    int n_sensor, n_part, HH, MM, SS;
    bool stop = false;
        
    cout << "start" << endl;
    cin >> n_sensor;
    
    sensore sensori;
    sensori.distanza = (int*) calloc (n_sensor, sizeof (int));
    for (int i = 1; i < n_sensor - 1; i++) {
        cin >> sensori.distanza[i];
    }
    sensori.distanza[n_sensor - 1] = 42;
    
    cin >> n_part >> HH >> MM >> SS;
    
    giocatore giocatori[n_part];
    for (int i = 0; i < n_part; i++) {
        giocatori[i].passaggio = (bool*) calloc (n_sensor, sizeof (bool));
        giocatori[i].ora_passaggio = (orario*) calloc (n_sensor, sizeof (orario));
    }
    
    while (!stop) {
        int sensore, ore, minuti, secondi, giocatore;
        
        cin >> sensore;
        if ((sensore < 0) || (sensore > n_sensor) || bool(cin) == false)
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
            controllo(giocatori + k, n_sensor, sensori);
            //potevo anche scrivere controllo (&giocatori[k], n_sensor, sensori);
        } catch (int tipo_baro) {
            errori++;
            if (tipo_baro == 1) cout << k << ": salto sensore" << endl;
            else cout << k << ": tempo sospetto" << endl;
        }
    }
    
    free (sensori.distanza);
    for (int i = 0; i < n_part; i++) {
        free(giocatori[i].passaggio);
        free(giocatori[i].ora_passaggio);
    }
    
    if (!errori) cout << "gara regolare" << endl;
    cout << "end" << endl;
}

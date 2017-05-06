#include<iostream>

using namespace std;

// Prototipi delle funzioni da implementare
bool leggiM(float *a, int &m, int &n);
void stampaM(float *a, int m, int n);
bool controllo_somma(int m1, int n1, int m2, int n2);
void somma(float *a, float *b, float *c, int m, int n);
bool controllo_prodotto(int m1, int n1, int m2, int n2);
void prodotto(float *a, float *b, float *c, int m, int n, int p);
void trasponi(float* a, float *b, int m, int n);

bool leggiM(float *a, int &m, int &n) {
    cin >> m >> n;
    for (int i = 0; i < m*n; i++) {
        cin >> *(a + i);
        if (bool(cin) == false)
            return false;
    }
    return true;
}

void stampaM(float *a, int m, int n) {
    cout << m << " " << n << endl;
    for (int i = 0; i < m * n; i ++) {
        cout <<a[i] << " ";
        if ((i + 1) % n == 0)
            cout << endl;
    }
}

bool controllo_somma(int m1, int n1, int m2, int n2) {
    return m1 == m2 && n1 == n2;
}

void somma(float *a, float *b, float *c, int m, int n) {
    for (int k = 0; k < m * n; ++k)
         *(c + k) = *(a + k) + *(b + k);
}

bool controllo_prodotto(int m1, int n1, int m2, int n2) {
    return n1 == m2;
}

void prodotto(float *a, float *b, float *c, int m, int n, int p) {
    int z = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int prodotto = 0;
            for (int k = 0; k < n; k++)
                prodotto = prodotto + a[i * n + k] * b[k * p + j];
            
            c[z++] = prodotto;
        }
    }
}

void trasponi(float* a, float *b, int m, int n) {
    int z = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m * n; j = j + n) {
            b[z++] = a[i + j];
        }
    }
}

int main() {
    float a[100], b[100], c[100];   // array con i dati
    int ma, na, mb, nb, mc, nc;     // dimensioni delle tre matrici
    char operazione;                // operazione da eseguire
    
    bool ok = true;
    bool enter = false;
    
    cout << "start" << endl;
    ok = leggiM(a, ma, na);
    cin >> operazione;

    while (bool(cin) && operazione != 'q' && ok)
    {
        if (operazione == '+') {
            bool test = true;
            if (!enter) {
                test = leggiM(b, mb, nb);
                enter = true;
            }
            if (test && controllo_somma(ma, na, mb, nb)) {
                mc = ma; nc = na;
                somma (a, b, c, mc, nc);
                stampaM (c, mc, nc);
            
                for (int i = 0; i < 100; i++)
                    a[i] = c[i];
                ma = mc; na = nc;
            }
            else
                cout << "dimensioni non corrette";
        }
        else if (operazione == '*') {
            bool test = true;
            if (!enter) {
                test = leggiM(b, mb, nb);
                enter = true;
            }
            if (controllo_prodotto (ma, na, mb, nb)) {
                mc = ma; nc = nb;
                prodotto (a, b, c, ma, na, nb);
                stampaM (c, mc, nc);
                
                for (int i = 0; i < 100; i++)
                    a[i] = c[i];
                ma = mc; na = nc;
                enter = true;
            }
            else
                cout << "dimensioni non corrette";
        }
        else if (operazione == 't') {
            trasponi (a, b, ma, na);
            stampaM (b, na, ma);
            
            for (int i = 0; i < 100; i++)
                    a[i] = b[i];
            ma = na; na = ma;
            enter = true;
        }
        
        cin >> operazione;
        if (bool(cin) && (operazione == '+' || operazione == '*'))
            ok = leggiM(b, mb, nb);
    }
    
    if (bool(cin) == false && operazione != 'q')
        cout << "ERRORE: input non corretto" << endl;
    
    cout << "end" << endl;
}

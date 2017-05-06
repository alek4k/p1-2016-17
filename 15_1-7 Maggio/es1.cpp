#include <iostream>

using namespace std;

// PRE = n >= 0
void stampa_verticale(int n);
// POST = stampa il numero n in verticale, con ogni cifra decimale in una riga diversa

int main() 
{
    cout << "start" << endl;
    
    int n;
    
    cin >> n;
    stampa_verticale(n);
    
    cout << "end" << endl;
}

void stampa_verticale(int n) {
    if (n < 10)
        cout << n << endl;
    else {
        stampa_verticale (n / 10);
        cout << n % 10 << endl;
    }
}

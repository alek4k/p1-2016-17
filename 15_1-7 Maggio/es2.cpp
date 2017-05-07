#include <iostream>

using namespace std;

// PRE = S e' una stringa di lunghezza n >= 1
bool palindroma(char *S, int n);
// POST = ritorna true se e solo se S e' palindroma

int main() 
{
    int lung;
    char S[100];
    cin.getline(S, 100);        // legge una riga di caratteri da cin
    lung = cin.gcount() - 1;    // ritorna il numero di caratteri letti (compreso il terminatore '\0')
    cout << "start" << endl;
    if (palindroma(S, lung))
        cout << "la stringa e' palindroma" << endl;
    else
        cout << "la stringa non e' palindroma" << endl;
    cout << "end" << endl;
}

bool palindroma(char *S, int n) {
    if (n <= 1)
        return true;
    return (*S != *(S + n - 1)) ? false : palindroma(S + 1, n - 2);
}

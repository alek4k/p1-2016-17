#include<iostream>
using namespace std;

int main()
{
    int t, p, tot;
    cin >> t >> p;
    
    tot = t + p;
    if (tot >= 18 && t <= 0)
      cout << "smanettone: bocciato, devi studiare di piu' la teoria" << endl;
    else if (t <= 0 && p < 18)
      cout << "bocciato: devi studiare ed esercitarti di piu'" << endl;
    else if (t > 0 && tot < 18)
      cout << "bocciato: devi esercitarti di piu'" << endl;
    else if (tot == 31 || tot == 32)
      cout << "congratulazioni: 30 e lode" << endl;     
    else
      cout << "il tuo voto e' " << tot << endl;
      
    cout << "end" << endl;
}


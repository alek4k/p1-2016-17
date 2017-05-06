#include <iostream>
#include "rational.h"

using namespace std;
using namespace Numbers;

int main() 
{
    cout << "start" << endl;
    Rational test (14, 4);
    Rational a, b, c;
    Rational test2 = reduce(test);
    char operazione;
    bool enter = false;
    
    cin >> a.numerator >> a.denominator >> operazione;

    while (operazione != 'q') {
        if (operazione == '+') {
            if (!enter) {
                cin >> b.numerator >> b.denominator;
                enter = true;
            }
            c = add(a, b);
            cout << c;
            a = c;
        }
        else if (operazione == '-') {
            if (!enter) {
                cin >> b.numerator >> b.denominator;
                enter = true;
            }
            c = sub(a, b);
            cout << c;
            a = c;
        }
        else if (operazione == '*') {
            if (!enter) {
                cin >> b.numerator >> b.denominator;
                enter = true;
            }
            c = mul(a, b);
            cout << c;
            a = c;
        }
        else {
            if (!enter) {
                cin >> b.numerator >> b.denominator;
                enter = true;
            }
            c = div(a, b);
            cout << c;
            a = c;
        }
        
        cin >> operazione;
        if (bool(cin) && operazione != 'q')
            cin >> b.numerator >> b.denominator;
    }
    
    cout << "end" << endl;
}

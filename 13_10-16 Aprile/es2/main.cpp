#include <iostream>
#include "rational.h"

using namespace std;
using namespace Numbers;

int main() 
{
    cout << "start" << endl;
    Rational a, c;
    bool ok = true;

    cin >> a.numerator >> a.denominator;

    if (a.numerator <= 0 || a.denominator <= 0 || a.numerator >= a.denominator)
        cout << "Input non corretto" << endl;
    else {
        while (ok) {
            Rational b (1, 2);
            bool dim = Numbers::less(a,b);
            while (dim) {
                b.denominator = b.denominator + 1;
                if (!Numbers::less(a,b))
                    dim = false;
            }
            cout << b << " + ";
            c = sub (a, b);
            if (c.numerator == 1) {
                cout << c << endl;
                ok = false;
            }
            else
                a = c;
        }
    }
    
    cout << "end" << endl;
}

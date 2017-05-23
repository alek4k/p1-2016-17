#include <iostream>
#include "code.h"

using namespace std;

int main() 
{
    coda Q;
    char c;
    
    cout << "start" << endl;
    
    cin >> c;
    while (c != '.') {
        if (c == '*') {
            char print = pop (Q);
            if (!print)
                cout << "vuota ";
            else 
                cout << print << " ";
        }
        else
            push (c, Q);
            
        cin >> c;
    }

    cout << "end" << endl;
}

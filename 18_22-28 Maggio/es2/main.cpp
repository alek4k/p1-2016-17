#include <iostream>
#include "code.h"

using namespace std;

int main() 
{
    coda Q;
    int n, k;
    cin >> n >> k;
    
    cout << "start" << endl;
    
    for (int i = 0; i < n; i++)
        push (i, Q);
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < k - 1; j++)
            push (pop(Q), Q);
        
        cout << pop (Q) << " eliminata" << endl;
    }
    
    cout << pop (Q) << " sopravvive" << endl;
    cout << "end" << endl;
}

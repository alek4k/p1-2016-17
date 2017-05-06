#include<iostream>
using namespace std;

int S (int *A, int n) {
    int index = -2, count = 0;
    bool stop = false;
    
    if (n == 0 && A[0] != -2)
        return 0;
    
    for (int i = 0; i < 400 && !stop; i++) {
        if (A[i] == -2)
            stop = true;
        else if (A[i] == -1) {
            count = count + 1;
            if (count == n)
                if (A[i + 1] != -2) {
                    index = i + 1;
                    stop = true;
                }
        }
    }
    
    return index;
}

main()
{
   int X[400];
   cin>>X[0];
   for(int i=1; i<400 && X[i-1]!=-2; i++)
   cin >>X[i];
    
    int a;
    cin>>a;
    cout<<"start"<<endl;
    int b=S(X,a); // da fare
    if(b==-2)
     cout<<"sottosequenza "<<a<<" non presente"<<endl;
    else
     cout<<"inizio sottosequenza "<<a<<" indice="<<b<<endl;
    cout<<"end"<<endl;
 }


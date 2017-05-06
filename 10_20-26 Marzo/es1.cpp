#include<iostream>
using namespace std;

void leggiV (int *A, int strati, int rig, int col, int n) {
    int stop, z = 0, q = 0;
    if (n > strati*rig*col)
        stop = strati*rig*col;
    else
        stop = n;
    
    for (int i = 0; i < stop; i++) {
        cin >> A[z];
        z = z + col;
        if (z >= strati * rig * col) {
            z = q + 1;
            q = z;
        }
    }
}

void stampaS (int *A, int strati, int rig, int col) {
    int z = 0, x = 0;
    for (int i = 0; i < strati; i++) {
        cout << "strato:" << i << endl;
        for (int j = 0; j < rig*col; j++) {
            cout << A[x++] << " ";
            z = z + 1;
            if (z == col) {
                cout << endl;
                z = 0;
            }
        }
    }
}

main()
{
   int X[400];
   for(int i=0; i<400; i=i+1)
     X[i]=-1;
   int lim1,lim2,lim3,n_ele;
   cin >> lim1 >>lim2>>lim3 >>n_ele;
   //
   leggiV(X,lim1,lim2,lim3,n_ele);
   cout<<"start"<<endl;
   stampaS(X,lim1,lim2,lim3);
   cout<<"end"<<endl;
}

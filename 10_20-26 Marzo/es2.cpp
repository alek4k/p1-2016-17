#include<iostream>
using namespace std;

int element_to_write (int strati, int rig, int col, int n) {
    int stop;
    if (n > strati*rig*col)
        stop = strati*rig*col;
    else
        stop = n;
        
    return stop;
}

int elementiRiga (int current_strato, int current_riga, int strati, int rig, int col, int n) {
    int vfettepiene = (n/(rig*strati));
    int items = vfettepiene;
    int n_ele_vfettaparziale = (n%(rig*strati));
    int current_riga_tot = (current_strato * rig + current_riga + 1);
    
    if (current_riga_tot <= n_ele_vfettaparziale)
        items = items + 1;
    
    return items;
}

void leggiV (int *A, int strati, int rig, int col, int n) {
    int z = 0, q = 0;
    int stop = element_to_write(strati, rig, col, n);
    
    for (int i = 0; i < stop; i++) {
        cin >> A[z];
        z = z + col;
        if (z >= strati * rig * col) {
            z = q + 1;
            q = z;
        }
    }
}

void stampaS (int *A, int strati, int rig, int col, int n) {
    int x = 0, marker = 0;
    int stop = element_to_write(strati, rig, col, n);
    
    for (int i = 0; i < strati && marker < stop; i++) {
        cout << "strato:" << i << endl;
        
        for (int j = 0; j < rig && marker < stop; j++) {
            int printable = elementiRiga (i, j, strati, rig, col, stop);
            for (int k = 0; k < printable; k++) {
                cout << A[x++] << " ";
                marker = marker + 1;
            }
            for (int h = 0; h < (col - printable); h++)
                x = x + 1;
            
            cout << endl;
        }
    }
}

main()
{
   int X[400];
   //for(int i=0; i<400; i=i+1)
     //X[i]=-1;
   int lim1,lim2,lim3,n_ele;
   cin >> lim1 >>lim2>>lim3 >>n_ele;
   //
   leggiV(X,lim1,lim2,lim3,n_ele);
   cout<<"start"<<endl;
   stampaS(X,lim1,lim2,lim3,n_ele);
   cout<<"end"<<endl;   
}

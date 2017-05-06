#include<iostream>
using namespace std;

void stampaS (int *A, int col, int elem, int strato) {
    cout << endl << "strato" <<  strato << endl;
    int k = 0, r_count = 0;
    
    for (int j = 0; j < elem; j++) {
        if (k == 0)
            cout << "r" << r_count << ":";
        cout << *(A+j) << " ";
        k = k + 1;
        if (k == col)
        {
            cout << endl;
            r_count = r_count + 1;
            k = 0;
        }
    }
}

main()
{
    int n_ele, lim1,lim2, lim3, X[400];
    cin>>n_ele;
    for(int i=0; i<n_ele; i=i+1)
        cin>>X[i];
    cin>>lim1>>lim2>>lim3;
    cout<<"start"<<endl;
    
    //da fare
    int sp = n_ele / (lim2 * lim3);
    int nrp = (n_ele % (lim2 * lim3)) / lim3;
    int ur = (n_ele % (lim2 * lim3)) % lim3;
    //numero strati da stampare:
    int s_print = sp;
    if (nrp > 0 || ur > 0)
        s_print = s_print + 1;
    
    for (int i = 0; i < s_print; i++) {
        int n_ele_faccia = 0;
        if (i < sp)
            n_ele_faccia = lim2 * lim3;
        else if (nrp > 0) {
            n_ele_faccia = nrp * lim3;
            if (ur > 0)
                n_ele_faccia = n_ele_faccia + ur;
        }
        else if (ur > 0)
            n_ele_faccia = ur;
            
        stampaS(X+i*lim2*lim3, lim3, n_ele_faccia, i);
    }
    
    cout << endl << "end" << endl;
}

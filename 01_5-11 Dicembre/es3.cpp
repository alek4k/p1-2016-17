#include<iostream>
#include<math.h>
using namespace std;

main()
{
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    if (a>0 && b>0 && c>0 && n>0)
        if (pow(a,n)+pow(b,n)==pow(c,n)){
            cout << "Si" <<endl;
            if (n>2)
                cout << "Fermat si sbagliava";
        }
        else
            cout << "No"<<endl;
    else
        cout << "Input sbagliato"<<endl;
    
    
        cout << "end"<<endl;
}

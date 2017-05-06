#include<iostream>
using namespace std;

main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a > 0 && b > 0 && c > 0)
    {
        if ((a + b > c)&&(a + c > b)&&(b + c > a))
            cout << "Si" <<endl;
        else
            cout << "No" <<endl;
    }
    else
        cout << "Input sbagliato"<<endl;
    
    cout << "end"<<endl;
}

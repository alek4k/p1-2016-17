#include<iostream>
using namespace std;

main()
{
    int n, m, z, temp;
    char space = ' ';
    char star = '*';
    
    cin >> n;
    m = n;
    z = 1;
    temp = 1;
    
    if (n <= 2)
        cout << "altezza non valida" <<endl;
    else
    {
        for (int i=n-1; i > 0; i--)
        {
            while (m-2 > 0)
            {
                cout << space;
                m--;
            }
            m = i;
            while (z > 0)
            {
                cout << star;
                z--;
            }
            temp=temp+2;
            z = temp;

            cout <<endl;
        }

        while (n-2 > 0)
        {
            cout << space;
            n--;
        }
        cout << star <<endl;
    }
    cout <<"end"<<endl;
}

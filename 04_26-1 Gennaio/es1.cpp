#include<iostream>
using namespace std;
main()
{
    int a, b, c, d, n;
    int hit = 0;
    bool match = false;
    bool quit = false;
    int temp = 4;
    
    cin >> n;
    
    if (n >= 4)
    {
        cin >> a;
        cin >> b;
        cin >> c;
        cin >> d;

        while (quit == false)
        {
            if (match == true)
            {
                cin >> a;
                cin >> b;
                cin >> c;
                cin >> d;
                match = false;
                temp = temp + 4;
            }
            
            if (a == (b + c + d))
            {
                hit = hit + 1;
                if (n-temp >= 4)
                    match = true;
                else
                    quit = true;
            }
            else
            {
                if (n-temp >= 1)
                {
                    a = b;
                    b = c;
                    c = d;
                    cin >> d;
                    temp = temp + 1;
                }
                else
                    quit = true;
            }
        }
        cout <<"trovate "<< hit << " quadruple" << endl;
    }
    else
        cout <<"non ci sono abbastanza numeri"<<endl;
    
    cout<<"end"<<endl;
}

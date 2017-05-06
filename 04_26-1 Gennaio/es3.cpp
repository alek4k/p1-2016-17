#include<iostream>
using namespace std;
main()
{
    bool isFinished = false;
    int c1 = 0, c2 = 0, c3 = 0, n, sum=0;

    while (!isFinished)
    {
        cin >> n;

        sum = sum + n;
        
        if (sum < 0)
        {
            c1 += 1;
            c2 = 0;
            c3 = 0;
        }
        else if (sum >= 0 && sum <= 10)
        {
            c2 += 1;
            c1 = 0;
            c3 = 0;
        }
        else
        {
            c3 += 1;
            c1 = 0;
            c2 = 0;
        }
        
        if (c1 == 5 || c2 == 5 || c3 == 5)
            isFinished = true;
    }
    
    if (c1 == 5)
        cout << "somma < 0 per 5 volte consecutive" << endl;
    else if (c2 == 5)
        cout << "somma tra 0 e 10 per 5 volte consecutive" << endl;
    else if (c3 == 5)
        cout << "somma > 10 per 5 volte consecutive" << endl;
    
    cout<<"end"<<endl;
}

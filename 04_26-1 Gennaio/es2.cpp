#include<iostream>
using namespace std;
main()
{
    bool isFinished = false;
    int temp = 0;
    int c1 = 0, c2 = 0, c3 = 0, n, sum = 0;

    while (!isFinished)
    {
        cin >> n;

        sum = sum + n;
        
        if (sum < 0)
            c1 += 1;
        else if (sum >= 0 && sum <= 10)
            c2 += 1;
        else
            c3 += 1;
        
        if (c1 == 5 || c2 == 5 || c3 == 5)
            isFinished = true;
    }
    
    cout << "somma < 0 per " << c1 << " volte" << endl;
    cout << "somma tra 0 e 10 per " << c2 << " volte" << endl;
    cout << "somma > 10 per " << c3 << " volte" << endl; 
    cout<<"end"<<endl;
}

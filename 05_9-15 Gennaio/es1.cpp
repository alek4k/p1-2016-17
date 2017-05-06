#include<iostream>
using namespace std;
main()
{
    int n;
    bool stop = false;
    bool palindroma = false;
    
    cin >> n;
    char sequence[n];
    int a = 0;
    int b = n - 1;

    if (n >= 1 && n <= 100)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> sequence[i];
        }
        
        while (!stop)
        {
            if (sequence[a++] == sequence[b--])
            {
                if (b < a)
                {
                    stop = true;
                    palindroma = true;
                }
            }
            else
                stop = true;            
        }
    }
    
    if (palindroma == true)
        cout << "La sequenza e' palindroma" << endl;
    else
        cout << "La sequenza non e' palindroma" << endl;
    
    cout<<"end"<<endl;
}

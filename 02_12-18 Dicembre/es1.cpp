#include<iostream>
using namespace std;

main()
{
    int n, win1, win2;
    char a, b;
    win1 = 0;
    win2 = 0;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (a=='f')
        {
            if (b=='c')
                win1++;
            else if (b=='s')
                win2++;
        }
        else if (a=='s')
        {
            if (b=='f')
                win1++;
            else if (b=='c')
                win2++;
        }
        else if (a=='c')
        {
            if (b=='s')
                win1++;
            else if (b=='f')
                win2++;
        }
    }
    
    if (win1 > win2)
        cout << "Vince il Giocatore 1"<<endl;
    else if (win2 > win1)
        cout << "Vince il Giocatore 2"<<endl;
    else
        cout << "Pareggio"<<endl;
    
    cout << "end"<<endl;
}

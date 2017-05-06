#include<iostream>
using namespace std;

main()
{
    char n;
    int pa = 0, pc = 0;
    bool pcf = false;
    
    do
    {
        cin >> n;
        if (n == '(')
            pa++;
        if (n == ')')
            pc++;
        if (pc > pa)
            pcf = true;
    }
    while (n != '0');
    
    if (pa > pc)
        cout <<"la sequenza NON e' bilanciata, ci sono parentesi aperte senza match"<<endl;
    else if (pcf == true)
        cout <<"la sequenza NON e' bilanciata, ci sono parentesi chiuse senza match"<<endl;
    else
        cout <<"la sequenza e' bilanciata"<<endl;
        
    cout <<"end"<<endl;
}

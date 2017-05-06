#include<iostream>
using namespace std;

main()
{
    char n;
    int pa = 0, pc = 0, pe=0;
    bool letto_e = false, letto_en = false, letto_end = false;
    
    do
    {
        cin >> n;
        if (n == '(')
            pa++;
        if (n == ')')
            pc++;
        if (pc > pa)
            pe++;
        if (n=='D' && letto_en)
            letto_end = true;
        if (n=='N' && letto_e)
            letto_en = true;
        else
            letto_en = false;
        if (n=='E')
            letto_e = true;
        else
            letto_e = false;
    }
    while (!letto_end);
    
    if (pe>=1)
        cout <<"la sequenza NON e' bilanciata, ci sono parentesi chiuse senza match"<<endl;
    else {
        if (pa == pc)
            cout <<"la sequenza e' bilanciata"<<endl;
        else{
            if (pa > pc)
                cout <<"la sequenza NON e' bilanciata, ci sono parentesi aperte senza match"<<endl;
            else
                cout <<"la sequenza NON e' bilanciata, ci sono parentesi chiuse senza match"<<endl;
            }
    }
    cout <<"end"<<endl;
}

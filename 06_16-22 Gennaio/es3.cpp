#include<iostream>
using namespace std;
main()
{
    int C[5][5];
    bool B[5][5];
    for(int i=0; i<5; i=i+1)
        for(int j=0; j<5; j=j+1)
            cin>>C[i][j];

    bool uguale = true;
  
    for (int i = 0; i < 5; i++)//R: Incrementa i cioè il numero di riga && 0<=i<=5 
    {
        for (int j = 0; j < 5; j++)
        /*R: Incrementa j cioè il numero di colonna && 0<=j<=5 
            Controlla lo stato della variabile booleana "uguale": se è true, riga e colonna in esame sono uguali
            altrimenti riga e colonna in esame sono diverse
        */
        {
            for (int k = 0; k < 5; k++)
            /*R: Confronta ogni cella della riga in esame con la cella nella rispettiva posizione nella colonna in esame.
                Appena due celle sono diverse, la variabile booleana "uguale" diventa false && 0<=k<=5 
            */
            {
                if (C[i][k] != C[k][j])
                    uguale = false;
            }
            if (uguale)
                B[i][j] = true;
            else
                B[i][j] = false;
                
            uguale = true;
        }
    }
        
  for(int i=0; i<5; i=i+1)
  { 
    cout<<"riga="<<i<<':';
    for(int j=0; j<5; j=j+1)
      cout<<B[i][j]<<' ';  
    cout<<endl;
   } 
 cout<<"end"<<endl;   
    
}

#include<iostream>
using namespace std;

int riga (int X[], int n)
{
      int sum = 0, k = 0;
      for (int i = 0; i < n; i++) {
        sum = sum + *(X+k);
        k = k + 1;
        if (k == 8)
            k = k + 4*8;
      }
     return sum;
}

main()
{
  int A[10][5][8], *p=A[0][0];
  int n_ele;
  cin>>n_ele;
  for(int i=0; i<n_ele; i=i+1)
    cin>>p[i];
  int bestfetta=-1,bestvalue;
  cout<<"start"<<endl;
  
  //da fare
  int sp = n_ele/40;
  int nrp = (n_ele%40)/8;
  int ur = (n_ele%40)%8;
  
  int max_righe = 0;
  if (sp > 0)
    max_righe = 5;
  else if (nrp > 0) {
    max_righe = nrp;
    if (ur > 0)
        max_righe = max_righe + 1;
  }
  else if (ur > 0)
    max_righe = 1;

  for (int i = 0; i < max_righe; i++) {
      int n_colonne = sp*8;
      if (i < nrp)
        n_colonne = n_colonne + 8;
      else if (ur > 0 && i == nrp)
        n_colonne = n_colonne + ur;
      
      int somma = riga (p+i*8, n_colonne);
      if (i == 0) {
        bestvalue = somma;
        bestfetta = i;
      }
      else if (somma >= bestvalue) {
          bestvalue = somma;
          bestfetta = i;
      }
  }

 cout<<"H-fetta massima= "<<bestfetta<<" con somma= "<<bestvalue<<endl;
 cout<<"end"<<endl;
}

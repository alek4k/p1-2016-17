#include<iostream>
using namespace std;

int colonna(int X[], int n, int step) {
    //da fare
    int sum = 0, z = 0;
    for (int j = 0; j < n; j++) {
        sum = sum + *(X + z);
        z = z + step;
    }
    return sum;
}

//PRE=(cin contiene n_ele, 0<n_ele<=400, seguito da n_ele interi qualsiasi)
main()
{
  int A[10][5][8], *p=A[0][0];
  int n_ele;
  cin>>n_ele;
  for(int i=0; i<n_ele; i=i+1)
    cin>>p[i];
  cout<<"start"<<endl;
  
  //da fare
  int bestfetta, bestvalue;
  int sp = n_ele/40;
  int nrp = (n_ele%40)/8; 
  int ur = (n_ele%40)%8;

  for (int i = 0; i < 8 && i < n_ele; i++) {
      int n_righe = 5*sp + nrp;
      if (i < ur)
        n_righe = n_righe + 1;
        
      int somma = colonna (p+i, n_righe, 8);
      
      if (i == 0) {
        bestvalue = somma;
        bestfetta = i;
      }
      else if (somma >= bestvalue) {
            bestvalue = somma;
            bestfetta = i;
      }
  }
  
  cout<<"V-fetta massima= "<<bestfetta<<" con somma= "<<bestvalue<<endl;
  cout<<"end"<<endl;
}
//POST=(stampa l'indice della V-fetta a somma massima seguito dalla sua somma e in caso di parità, stampa l'indice massimo)

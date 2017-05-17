#include<iostream>

using namespace std;

bool trova(int*L, int n, int e, int*P);
bool trova_lab (int*L, int dim, int i, int j, int*P);
void stampa(int*P, int n, int c);

main()
{
  int n;
  cin>>n;
  int* L= new int [n*n], *P=new int[n];
  for(int i=0; i<n*n; i++)
          cin>>L[i];
  bool x=trova(L,n,0,P);//da fare
  cout<<"start"<<endl;
  if(x)
    { cout<<"il cammino e':"; stampa(P,n,0);}//da fare
  else
    cout<<"il cammino non esiste"<<endl;
  cout<<"end"<<endl;
}

bool trova (int*L, int dim, int n, int*P) {
    if (n > dim - 1)
        return false;
        
    if (trova_lab (L, dim, 0, n, P))
        return true;
    else
        return trova (L, dim, n + 1, P);
}

bool trova_lab (int*L, int dim, int i, int j, int*P) {
    if (*(L + (i*dim) + j) == 0 || j < 0 || j > dim - 1)
        return false;
    else
        *P = j;
    if (i == dim - 1)
        return true;
    
    return trova_lab(L, dim, i + 1, j - 1, P + 1) || trova_lab(L, dim, i + 1, j, P + 1) || trova_lab(L, dim, i + 1, j + 1, P + 1);
}

void stampa(int*P, int n, int c) {
    if (c == n)
        return;
        
    cout << "(" << c << "," << *P << ") ";
    stampa (P + 1, n, c + 1);
}

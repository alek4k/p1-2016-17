#include<iostream>
using namespace std;

bool trova_lab (int * L, int dim, int i, int j);
bool trova (int *L, int dim, int n);

main()
{
  int n;
  cin>>n;
  int L[n*n];
  for(int i=0; i<n*n; i++)
          cin>>L[i];
  bool x=trova(L, n, 0);
  if(x)
    cout<<"il cammino esiste"<<endl;
  else
    cout<<"il cammino non esiste"<<endl;
}

bool trova (int *L, int dim, int n) {
    if (n > dim - 1)
        return false;
        
    if (trova_lab (L, dim, 0, n))
        return true;
    else
        return trova (L, dim, n + 1);
}

bool trova_lab (int * L, int dim, int i, int j) {
    if (*(L + (i*dim) + j) == 0 || j < 0 || j > dim - 1)
        return false;
    if (i == dim - 1)
        return true;
        
    return trova_lab(L, dim, i + 1, j) || trova_lab(L, dim, i + 1, j + 1) || trova_lab(L, dim, i + 1, j - 1);
}

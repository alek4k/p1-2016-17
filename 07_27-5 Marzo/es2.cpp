#include<iostream>

using namespace std;

main()
{
  
  int A[6][8];
  bool B[6][8];
  for(int i=0; i<6; i=i+1)
    for(int j=0; j<8; j=j+1)
      cin>>A[i][j];

  for(int i=0; i<6; i=i+1)
    for(int j=0; j<8; j=j+1)
     {
       bool ok = true;
       for (int k=0; k<8 && ok; k++){
           if (A[i][k] != A[i][j])
               for (int z=0; z<6 && ok; z++)
                   if (A[i][k] == A[z][j])
                     ok = false;
       }
            B[i][j] = ok;
     } 
     
  cout<<"start"<<endl;
  for(int i=0; i<6; i=i+1)
   {
    for(int j=0; j<8; j=j+1)
      cout<<B[i][j]<<' ';
    cout<<endl;
   }
  cout<<"end"<<endl;
}

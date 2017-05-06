#include<iostream>
using namespace std;

int a = 5;
main()
{
    int A[6][8]; bool B[6][8];
    for(int i=0; i<6; i=i+1)
     for(int j=0; j<8; j=j+1)
        cin>> A[i][j];
        
//parte da fare
    for(int i=0; i<6; i=i+1)
    {
      for(int j=0; j<8; j=j+1)
      {
          bool stop = false;
          bool check = false;
          for (int k = 0; k < 8 && !stop; k++)
          {
              check = false;
              for (int z = 0; z < 6; z++)
              {
                  if (A[i][k] == A[z][j])
                    check = true;
              }
              if (!check){
                B[i][j] = false;
                stop = true;
              }
          }
          if (check)
            B[i][j] = true;
       }
    }
    for(int i=0; i<6; i=i+1)
    {
        for(int j=0; j<8; j=j+1)
        {
         if (j == 0)
           cout << B[i][j];
         else 
           cout << " " << B[i][j];
        }
        cout << endl;
    }
}

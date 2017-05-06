#include<iostream>
using namespace std;
main()
{
 int A[8][6];
 bool B[8][6];
 int* p=*A;
 for (int i=0; i<48; i++)
  cin >> p[i];

 // da fare
 int C[5];
 int usage = 0;
  for(int i=0; i<8; i=i+1)
    {
      for(int j=0; j<6; j=j+1)
      {
          bool stop = false;
          bool check = false;
          bool used = false;
          bool stop2 = false;
          usage = 0;
          for (int k = 0; k < 6 && !stop; k++)
          {
              check = false;
              stop2 = false;
              
              for (int z = 0; z < 8 && !stop2; z++)
              {
                  for (int m = 0; m < usage; m++)
                  {
                      if (z == C[m])
                        used = true;
                  }
                  
                  if (!used && A[i][k] == A[z][j]) {
                      C[usage++] = z;
                      check = true;
                      stop2 = true;
                  }
                  used = false;
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
    for(int i=0; i<8; i=i+1)
    {
        for(int j=0; j<6; j=j+1)
        {
         if (j == 0)
           cout << B[i][j];
         else 
           cout << " " << B[i][j];
        }
        cout << endl;
    }
 
 cout << "end";
}

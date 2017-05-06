#include<iostream>
using namespace std;
main()
{
  cout<<"start"<<endl;
  
  int A[6][6];
  for(int i=0; i<6; i=i+1)
    for(int j=0; j<6; j=j+1)
      cin >> A[i][j];
  
  bool found1 = true;
  bool found2 = true;
  int save1 = -1;
  int save2 = -1;
  
  for (int a = 0; a < 6 && found1; a++)
  {
      found1 = false;
      for (int b = 0; b < 6 && !found1; b++)
      {
            if (A[a][a] == A[b][5-b]){
                found1 = true;
            }
      }
     if(!found1){
        save1 = A[a][a];
     }
  }
  for (int a = 0; a < 6 && found2; a++)
  {
      found2 = false;
      for (int b = 0; b < 6 && !found2; b++)
      {
            if (A[a][5-a] == A[b][b]){
                found2 = true;
            }
      }
     if(!found2){
        save2 = A[a][5-a];
     }
  }

  if (save1 < 0 && save2 < 0)
    cout << "le due diagonali contengono gli stessi valori" << endl;
  if (save1 >= 0)
    cout << "diagonale principale contiene " << save1 << " che non e' sulla diagonale secondaria" << endl;
  if (save2 >= 0)
    cout << "diagonale secondaria contiene " << save2 << " che non e' sulla diagonale principale" << endl;
  
  cout << "end" << endl;
}

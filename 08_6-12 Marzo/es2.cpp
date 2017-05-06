#include<iostream>
using namespace std;

main()
{
  cout<<"start"<<endl;
  int A[3][4][5], *p=**A /*oppure *p = A[0][0]*/, n_ele;
  cin>>n_ele;
  for(int i=0; i<n_ele; i=i+1)
    cin>>p[i];
  char c;
  int f;
  cin >> c >> f;
  
  int next = 0;
  //int sp = n_ele/20;
  //int nrp = (n_ele%20)/5;
  //int ur = (n_ele%20)%5;

  if(c=='H')
  {
      //stampa H fetta
      for (int j = f * 5; j < n_ele; j++) {
        cout << p[j] << " ";
        next = next + 1;
        if (next == 5) {
            cout << endl;
            next = 0;
            j = j + (3*5);
        }
      }
      
      if (f * 5 > n_ele)
        cout << "fetta richiesta vuota" << endl;
  }
  else
  {
      //stampa V fetta
      for (int j = f; j < n_ele; j++) {
        cout << p[j] << " ";
        next = next + 1;
        j = j + 4;
        if (next == 5) {
            cout << endl;
            next = 0;
        }
      }
      
      if (f >= n_ele)
        cout << "fetta richiesta vuota" << endl;
  }

  cout<<"endl"<<endl;
}

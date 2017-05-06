#include<iostream>
using namespace std;
main()
{
  int A[100], n, x;
  cin >> n;
  for(int i=0; i<n; i=i+1)
  cin >> A[i];
  int resta = 0;
  for(int i=0; i<n; i=i+1)
  {
      if (A[i] != x)
      {
          A[resta++] = A[i];
      }
  }
  n = resta;
  cout<<"n="<<n<<endl;
  for(int i=0; i<n; i=i+1)
   cout<< A[i]<<' ';
  cout<<endl<<"end"<<endl;
}

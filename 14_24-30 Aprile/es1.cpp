#include<iostream>
using namespace std;
 
void IC(int*C, int*X, int & lim) {
    int i = 0, y = 0, count = 0;
    bool newseq = true;
    while (C[i] != -2) {
        if (C[i] != -1 && newseq) {
            X[y++] = i;
            newseq = false;
            count += 1;
        }
        else if (C[i] != -1 && !newseq) {
            count += 1;
        }
        else if (C[i] == -1 && newseq) {
            X[y++] = i;
            X[y++] = 0;
            count = 0;
            lim += 1;
        }
        else if (C[i] == -1 && !newseq) {
            X[y++] = count;
            count = 0;
            lim += 1;
            newseq = true;
        }
        i += 1;
    }
    return;
}

main()
{
  int C[200], X[200];
  int x=0, lim=0;
  for(int i=0; x!=-2; i++)
   {cin>>x; C[i]=x;}
  cout<<"start"<<endl;
  IC(C,X,lim);
  for(int i=0; i<lim; i++)
    cout<<X[i*2]<<' '<<X[i*2+1]<<endl;
  cout<<"end"<<endl;
}

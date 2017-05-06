#include<iostream>

using namespace std;

int main()
{
    // inserire il codice del programma qui sotto
    int a,b,c,d;
    cin >> a >> b >> c;
    if (a > b)
      if (a > c)
         d = a;
      else
         d = c;
    else
      if (b > c)
         d = b;
      else
         d = c;    
             
    // alla fine il programma deve SEMPRE scrivere "end" sullo schermo
    cout << "il massimo e': "<< d << endl <<"end" << endl;
}

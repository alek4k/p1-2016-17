#include<iostream>
using namespace std;

int main()
{
   char a, b;
   cin >> a >> b;

   if (((a=='f') || (a=='c') || (a=='s'))&&((b=='f') || (b=='c') || (b=='s')))
   {
      if (a==b)  
         cout << "pareggio" << endl;
      else if (a=='f')
         if (b=='c')
            cout << "vince il giocatore 1" << endl;
         else
            cout << "vince il giocatore 2" << endl;
      else if (a=='c')
         if (b=='f')
            cout << "vince il giocatore 2" << endl;
         else
            cout << "vince il giocatore 1" << endl;
      else if (a=='s')
         if (b=='f')
            cout << "vince il giocatore 1" << endl;
         else
            cout << "vince il giocatore 2" << endl;
   }
   else
      cout << "mossa non valida" << endl;

   cout << "end" << endl;
}


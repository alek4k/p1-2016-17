#include<iostream>
using namespace std;

struct nodo{char info; nodo* left,*right; nodo(int a=0, nodo*b=0,nodo*c=0){info=a; left=b; right=c;}};

nodo* parse(char*& A)
{
  if(*A>='a' && *A<='z')
    {
      char p=*A;
      if(*(A+1) !='(') throw (1);
      A=A+2;
      nodo*l=parse(A);
      if(*A != ',') throw (2);
      A=A+1;
      nodo*r=parse(A);
      if(*A !=')') throw(3);
      
      A=A+1;
      return new nodo(p,l,r);
    }
  else
    if(*A=='_') {A=A+1;return 0;}
    else
      throw (4);
}

void  mleaf(nodo* r, int prof, int & minprof, nodo *&minleaf) {
    if (minleaf && prof >= minprof)
        return;
    
    if (!r->left && !r->right) {
        if (!minleaf || minprof > prof) {
            minprof = prof;
            minleaf = r;
        }
    }
    else {
        if (r->left)
            mleaf (r->left, prof + 1, minprof, minleaf);
        if (r->right)
            mleaf (r->right, prof + 1, minprof, minleaf);
    }
}

main() {
try
  {
    char A[100],y,*q=A;
    
    while(y!='$')
      {
	cin>>y;
	*q=y;
	q++;
      }
    q=A;
    nodo* R=parse(q);
    cout<<"start"<<endl;
    int a;
    nodo*b=0;
    mleaf(R,0,a,b);
    cout<<"prof="<<a<<" info foglia="<< b->info<<endl;
    cout<<"end"<<endl;
  }
 catch(int x)
   {
     switch(x)
       {
       case 1: cout<<"manca ("<<endl;   break;
       case 2: cout<<"manca ," <<endl; break;
       case 3: cout<<"manca )"<<endl;   break;
       case 4: cout<<"non albero"<<endl;   break;
       }
   }
}

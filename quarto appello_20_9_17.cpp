
 
  #include<iostream>
  using namespace std;
    
     struct nodo{int num, info; nodo* next; nodo(int a=0,int b=0, nodo* c=0){num=a; info=b; next=c;}}; // nodo di lista
     struct FIFO{nodo* primo, *ultimo; FIFO(nodo*a=0, nodo*b=0){primo=a; ultimo=b;}};
     struct nodoF{FIFO info; nodoF*next; nodoF(FIFO a=FIFO(),nodoF*b=0){info=a; next=b;}}; //nodo di lista con FIFO
    
     FIFO push_end(FIFO a, nodo*b)
    {
      b->next=0;
      if(!a.primo)
      {a.primo=a.ultimo=b;}
      else
       {a.ultimo->next=b; a.ultimo=b;}
      return a;
    }
   
    FIFO push_begin(FIFO a, nodo* b)
    {
     if(!a.primo)
       {a.primo=a.ultimo=b; b->next=0; return a;}
     else
      {
       b->next=a.primo;
       a.primo=b;
       return a;
      }
    }
   
      void stampa_L(nodo*L)
    {
     if (L)
       {cout<<'['<<L->num<<','<<L->info<<']'<<' '; stampa_L(L->next);}
     else
       cout<<endl;
    
    }
    void stampa_F(nodoF* x)
    {
      if(x)
        {
          stampa_L(x->info.primo);
          cout<<endl;
          stampa_F(x->next);
        }
    }
    
    nodo* costruisci(int n, int dim)
    {
     if(dim)
       {int x; cin>>x; return new nodo(n,x,costruisci(n+1,dim-1));}
     return 0;
    }
    nodo* clone(nodo*a)
    {
     if(a)
       {return new nodo(a->num, a->info, clone(a->next));}
     return 0;
    }
   
    //PRE=(lista(L) corretta
    FIFO eliminaR (nodo*&L, int x){
        if(!L){
            return FIFO();
        }
        if(L->info==x){
            nodo*tmp=L;
            L=L->next;
            tmp->next=0;
            FIFO d=eliminaR(L,x);
            d=push_begin(d,tmp);  // al ritorno quindi push_begin
            return d;
        }
        else{
            return eliminaR(L->next,x);
        }
    }
    // POST=(L è vL da cui sono stati eliminati tutti i nodi con info=x)&&(viene restituito un valore FIFO che gestisce la lista dei nodi tolti nello stesso ordine che hanno in vL)
   
   
    //PRE=(lista(Q) è corretta e ordinata rispetto ai campi info delle liste gestite dai suoi nodi,x gestisce lista non vuota)
    nodoF* insR(nodoF*Q, FIFO x){
        if(!Q){
            return new nodoF(x,0);
        }
        if(x.primo->info<Q->info.primo->info){
            return new nodoF(x,Q);
        }
        if(Q->next){
            if(Q->info.primo->info<x.primo->info && Q->next->info.primo->info>x.primo->info){
                Q->next=new nodoF(x,Q->next);
                return Q;
            }
        }
        Q->next=insR(Q->next,x);
        return Q;
    }
    //POST=(restituisce Q a cui è stato aggiuntoun nodoF che contiene x in modo da mantenere l’ordine dei campi info delle liste gestite dai  suoi nodi)
   
   
    //PRE=(lista(L) è corretta, vL=L)
    nodoF* tieni_primo_ric(nodo*& L){
        if(!L){
            return 0;
        }
        FIFO x=eliminaR(L->next,L->info);
        if(x.primo){
            nodoF*z=tieni_primo_ric(L->next);   //stack dei dati,salvo la FIFO x
            z=insR(z,x);
            return z;
        }
        else{
            return tieni_primo_ric(L->next);
        }
    }
    //POST:=(L contiene tanti  nodi quanti sono i diversi campi info di vL e per ciascun campo info di vL contiene
    //esattamente il primo nodo con quel valore di info)&&(la funzione restituisce col return una
    //lista di nodi nodoF i cui nodi gestiscono i nodi ripetuti di vL nel modo spiegato nell’esempio)
   
   
 //PRE=(lista(Q) è corretta e ordinata rispetto ai campi info delle liste gestite dai suoi nodi,x gestisce lista non vuota)
    nodoF* insI(nodoF*Q,FIFO x){
        if(!Q){
            return new nodoF(x,0);
        }
        if(x.primo->info<Q->info.primo->info){
            return new nodoF(x,Q);
        }
        nodoF*tmp=Q;
       while(tmp->next && tmp->next->info.primo->info<x.primo->info){
           tmp=tmp->next;
       }
       if(!tmp->next){
         tmp->next=new nodoF(x,0);    
       }
       else{
           tmp->next=new nodoF(x,tmp->next);
       }
       return Q;
   }
   //POST:(restituisce Q a cui è stato aggiuntoun nodoF che contiene x in modo da mantenere l’ordine dei campi info delle liste gestite dai  suoi nodi)
  
 
 //PRE=(lista(L) è corretta, vL=L)
   nodoF* tieni_primo_iter(nodo*& L){
     nodoF*z=0;
      FIFO tenuti=0;
     while(L){
         nodo*tmp=L;
         L=L->next;
        tmp->next=0;
       FIFO x=eliminaR(L,tmp->info);
          if(x.primo){
            z=insI(z,x);
          }
           tenuti=push_end(tenuti,tmp);  //all'andata quindi push_end
      }
      L=tenuti.primo;
  return z;
}
//POST:L contiene tanti  nodi quanti sono i diversi campi info di vL e per ciascuncampo info di vL contiene
//esattamente il primo nodo con quel valore di info)&&(la funzione restituisce col return una lista di nodi nodoF i cui nodi
//gestiscono i nodi ripetuti di vL nel modospiegato nell’esempio)
 
main()
{
  int dim;
  cout<<"start"<<endl;
  cin>>dim;
  nodo*C=costruisci(0,dim);
  nodo* D=clone(C);
  cout<<"Lista costruita"<<endl;
  stampa_L(C);
  nodoF* a =tieni_primo_ric(C); //da fare
  cout<<"soluzione ricorsiva"<<endl<<"nodi tolti:"<<endl;
   
  stampa_F(a);
  cout<<"lista rimanente:"<<endl;
  stampa_L(C);
  nodoF* b=tieni_primo_iter(D); //da fare
  cout<<"soluzione iterativa"<<endl<<"nodi tolti:"<<endl;
  stampa_F(b);
  cout<<"lista rimanente:"<<endl;
  stampa_L(D);
  cout<<"end";
}


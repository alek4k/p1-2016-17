#include<iostream>
using namespace std;

struct nodo{int info; nodo*next; nodo(int a=0, nodo*b=0){info=a; next=b;}};
struct FIFO {nodo* primo, *ultimo; int dim; FIFO(nodo*a=0,nodo*b=0,int c=0){primo=a; ultimo=b; dim=c;}};
struct nodoFIFO{FIFO info; nodoFIFO* next; nodoFIFO(FIFO a=FIFO(), nodoFIFO*b=0){info=a; next=b;}};
  
void stampa(nodoFIFO*Q,int i)
{
    if(Q)
      {
	cout<<"nella FIFO n."<< i<<" ci sono "<<Q->info.dim<<" valori, il primo e l'ultimo seguono:"<<endl;
        cout<<"primo="<<Q->info.primo->info<<", ultimo="<<Q->info.ultimo->info<<endl;
        stampa(Q->next,i+1);
      }

    //cout<<endl;
}

//PRE=(x gestisce una lista non vuota ordinata in modo crescente)
FIFO addord (FIFO x, nodo*N) { //iterativa
    if (x.primo->info > N->info) {
        N->next = x.primo;
        return FIFO(N, x.ultimo, x.dim + 1);
    }
    
    nodo* scorri = x.primo;
    /*  CORRETTEZZA: DOMANDA 1
     *  R ciclo => scorri e' nodo valido, chiamiamo nodo*a = scorri->next. se a e' puntatore a nodo valido e con campo info minore di N->info allora scorri = a;
     *  condizione di permanenza => a nodo valido e ha campo info minore di N->info
     *  condizione di uscita (permanenza negata) => a e' un nodo non valido (a = NULL) oppure a ha campo info maggiore di N->info
     */
    while (scorri->next && scorri->next->info < N->info) {
        scorri = scorri->next;
    }
    /*  POST del ciclo => scorri punta all'ultimo nodo della lista con campo info minore di N->info.
     *  Quindi il nuovo nodo N deve essere inserito in scorri->next al fine di mantenere l'ordine crescente dei campi info nella lista.
     *  Sempre in termini di nodo* a, nella post risulta che a, se esite, e' il primo nodo della lista con campo info maggiore di N->info.
     *  Quindi se a esiste sara' il primo nodo che dovra' seguire il nuovo nodo N all'interno della lista, mentre vecchio_a sara' il puntatore al nodo precedente di N;
     *  Se a=NULL, allora N verra' aggiunto in coda alla lista.
     */
    
    scorri->next = new nodo(N->info, scorri->next);
    if (!scorri->next->next) {
        x.ultimo = scorri->next;
    }
    x.dim = x.dim + 1;
    
    return x;
}
/*POST=(restituisce una FIFO che gestisce una lista che è quella gestita da x a cui è stato aggiunto il nodo N mantenendo l’ordinamento, i campi primo,
ultimo e  dim del valore FIFO restituito devono essere corretti rispetto alla lista che gestisce, in particolare, il campo  dim deve essere
incrementato di 1 rispetto a x.dim iniziale)*/

//CORRETTEZZA: DOMANDA 2
/*  cond. permanenza negata => condizione di uscita scritta sopra;
 *  Dimostrare che R + cond. uscita = POST del ciclo
 *  Considero sempre il puntatore a nodo a introdotto prima.
 *  Dal momento che a, mentre il ciclo avanza, diventa uguale a vecchio_a->next, sto' scorrendo la lista verso la fine.
 *  La condizione di uscita impone di uscire dal ciclo quando a non esiste oppure quando a ha campo info maggiore del nodo da inserire.
 *  Se a non esiste, allora esco dal ciclo con scorri che punta a vecchio_a, quindi all'ultimo nodo NON NULLO della lista.
 *  In questo caso la POST e' verificata: vechio_a ha campo info minore di N->info ed e' l'ultimo nodo della lista, quindi il nuovo nodo N deve essere inserito dopo scorri(vecchio_a).
 *  Se invece a esiste, allora l'uscita dal ciclo si e' verificata perche' a ha campo info maggiore di N->info.
 *  In questo caso a sara' il puntatore al nodo che dovra' seguire il nuovo nodo N in quanto ha campo info maggiore di N->info.
 *  Si ha quindi verificata la POST del ciclo che informa del raggiungimento del nodo che precedera' il nuovo nodo N (dal momento che mi fermo a quello che ho chiamato vecchio_a)
 *  e il nodo da inserire sara' per l'appunto inserito in vecchio_a->next.
 */

//CORRETTEZZA: DOMANDA 3
/*  una volta che ho eseguito il ciclo, dalla POST del ciclo dimostrata nella domanda 2, so che scorri punta ora al nodo che precedera' il nuovo nodo N da inserire.
 *  chiamo nodo* temp = scorri->next;
 *  se temp = NULL, scorri -> next viene fatto puntare ad un nuovo nodo che ha come campo info il valore di N->info e come campo next temp, quindi NULL.
 *  Questo si verifica quando N viene inserito in coda alla lista. In questo caso viene aggiornato il puntatore 'ultimo' della lista che puntera' ora al nuovo
 *  nodo situato in scorri->next; Viene poi incrementata la dimensione della variabile dim della lista perche' un nuovo nodo e' stato aggiunto.
 *  se temp e' un nodo valido non nullo invece, scorri -> next viene fatto puntare ad un nuovo nodo che ha come campo info il valore di N->info e come
 *  campo next temp, quindi il nodo che prima seguiva scorri e che ora seguira' il nuovo nodo inserito.
 *  In questo caso non aggiorno il puntatore 'ultimo' perche' il nuovo nodo non e' stato inserito in coda alla lista.
 *  Viene poi incrementata la dimensione della variabile dim della lista perche' un nuovo nodo e' stato aggiunto.
 */

nodo* poplast (FIFO& x) { //iterativa
    x.dim = x.dim - 1;
    
    //ho solo un nodo
    if (!x.primo->next) {
        nodo*result = x.primo;
        x = FIFO();
        return result;
    }
    
    //ho piu' nodi
    nodo* scorri = x.primo;
    //CORRETTEZZA: DOMANDA 1 applicata alla poplast
    //R ciclo => Chiamato nodo*a = scorri->next, a e' sempre un nodo valido. Chiamiamo nodo*t il nodo tale che t = a->next; a = vecchio_a->next;
    //condizione di permanenza => t nodo valido non nullo (a->next nodo valido non nullo)
    //condizione di uscita (permanenza negata) => t = NULL ovvero a->next = NULL;
    while (scorri->next->next) { 
        scorri = scorri->next;
    }
    /*POST del ciclo => scorri punta al penultimo nodo della lista, ovvero al nodo precedente rispetto a quello da eliminare;
    scorri->next e' il nodo da eliminare.
    Sempre in termini di nodi a e t, t e' nullo mentre a e' l'ultimo nodo della lista*/
    nodo*result = scorri->next;
    scorri->next = 0;
    x.ultimo = scorri;

    return result;
}
//CORRETTEZZA: DOMANDA 2 applicata alla poplast
/*  cond. permanenza negata => condizione di uscita scritta sopra;
 *  Dimostrare che R + cond. uscita = POST del ciclo
 *  Considero sempre i puntatori a nodo a e nodo t introdotti prima.
 *  Dal momento che a, mentre il ciclo avanza, diventa uguale a vecchio_a->next, sto' scorrendo la lista verso la fine. t punta sempre al nodo successivo di a, se esiste.
 *  La condizione di uscita impone di uscire dal ciclo quando t = NULL, quindi il nodo successivo di a non esiste.
 *  Tale condizione si verifica solamente una volta che a punta all'ultimo nodo della lista. Quindi vecchio_a sara' il punultimo nodo della lista.
 *  t invece punta a cio' che punta il campo next dell'ultimo nodo, ovvero a NULL.
 *  Si ha quindi verificata la POST del ciclo che informa del raggiungimento del penultimo nodo (dal momento che mi fermo a quello che ho chiamato vecchio_a)
 *  e il nodo da cancellare e' per l'appunto vecchio_a->next ovvero a che non e' altro che il puntatore all'ultimo nodo (che vogliamo rimuovere!).
 */

nodoFIFO* addtolist (nodoFIFO*Q, nodo*N, int m) { //ricorsiva che usa le 2 iterative
    if (!Q) return new nodoFIFO(FIFO(N, N, 1)); //CB1: Q vuota, inserisco N nella prima FIFO()
    
    if (Q->info.dim < m) { //CB2: Q->info corrente non e' piena, inserisco qui N in modo ordinato
        Q->info = addord(Q->info, N);
        return Q;
    }
    
    if (Q->info.ultimo->info > N->info) {
        nodo* rimosso = poplast(Q->info);
        if (Q->info.primo) {
            Q->info = addord(Q->info, N);
        }
        else {
            Q->info = FIFO(N, N, 1);
        }
        Q->next = addtolist(Q->next, rimosso, m); //R1
    }
    else {
        Q->next = addtolist(Q->next, N, m); //R2
    }
    
    return Q;
}

  main()
    {
      int n, m,a;
      cin>>n>>m;
      nodoFIFO* Q=0;
      for(int i=0; i<n; i++)
	{
	  cin >>a;
	  nodo*N=new nodo(a);
	  Q=addtolist(Q,N,m);//da fare
	}
      cout<<"start"<<endl;
      stampa(Q,0);
      cout<<"end"<<endl;
    }

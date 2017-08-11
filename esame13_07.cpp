#include<iostream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo*b=0){info=a; next=b;}};
struct nodoD{int lascia,togli; nodoD* next; nodoD(int a=0, int b=0,  nodoD*c=0){lascia=a; togli=b;  next=c;}};
struct doppioN{nodo*  La, *To; doppioN(nodo*a=0,nodo*b=0){La=a; To=b;}};

nodo* build(int n)
{
	if(n)
	{
		int x;
		cin>>x;
		return new nodo(x,build(n-1));
	}
	return 0;
}
nodoD* buildD(int n)
{
	if(n)
	{
		int x,y;
		cin>>x>>y;
		return new nodoD(x,y,buildD(n-1));
	}
	return 0;
}

void stampaL(nodo*L)
{
	if(L)
	{
		cout<<L->info<<' ';
		stampaL(L->next);
	}
	else
		cout<<endl;
}
void stampaD(nodoD*L)
{
	if(L)
	{
		cout<<'['<<L->lascia<<','<<L->togli<<']'<<' ';
		stampaD(L->next);
	}
	else
		cout<<endl;
}

nodo* conc(nodo*L1, nodo*L2)
{
	if(!L1) return L2;
	if(!L2) return L1;
	nodo* x=L1;
	while(x->next)
		x=x->next;
	x->next=L2;
	return L1;
}

nodo*clone(nodo*L)
{
	if(!L) return 0;
	return new nodo(L->info,clone(L->next));
}

nodo* taglia(nodo*&L, int n) {
	if (!L || !n) return 0;
	
	nodo* result = new nodo(L->info);
	nodo* temp = result;
	bool run = L->next;
	
	while (n > 0 && run) {
		L = L->next;
		temp->next = new nodo(L->info);
		if (n - 1 > 0)
			temp = temp->next;
		n--;
		run = L->next;
	}
	if(!run) L = NULL;
	temp->next = 0;
	
	return result;
}

nodo* tagliaric(nodo*&L, int n) {
	if (!L || !n) return 0;
	
	int temp = L->info;
	L = L->next;
	return new nodo(temp, tagliaric(L, n-1));
}

nodo* concric(nodo*L1, nodo*L2) {
	if(!L1) return L2;
	if(!L2) return L1;
	
	return new nodo(L1->info, concric(L1->next, L2));
}

void Fiter(nodo*L, nodoD* D, nodo*& lasciati, nodo*& tolti) {
	while (D) {
		lasciati = conc(lasciati, taglia(L, D->lascia));
		tolti = conc(tolti, taglia(L, D->togli));

		D = D->next;
	}
	if (L)
		lasciati = conc(lasciati, L);
}

doppioN Fric(nodo*L, nodoD*D) {
	if(!D) {
		if(L)
			return doppioN(L);
		
		return doppioN();
	}
	
	nodo* lasciati = tagliaric(L, D->lascia);
	nodo* tolti = tagliaric(L, D->togli);
	doppioN result = Fric(L, D->next);
	result.La = concric(lasciati, result.La);
	result.To = concric(tolti, result.To);
	return result;
}

int main()
{
	int dimL, dimD;
	cin>> dimL>>dimD;
	nodo* L= build(dimL);//data
	nodoD* D=buildD(dimD);//data
	nodo*L1=clone(L);//data
	cout<<"start"<<endl;
	stampaL(L); //data
	stampaD(D);//data
	nodo* lasciati=0, *tolti=0;
	Fiter(L,D, lasciati, tolti); //da fare
	stampaL(lasciati);
	stampaL(tolti);
	doppioN y=Fric(L1,D); //da fare
	stampaL(y.La);
	stampaL(y.To);
	cout<<"end"<<endl;
}


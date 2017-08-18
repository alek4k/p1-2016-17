#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}}; // nodo di lista
struct FIFOX{nodo* primo, *ultimo; int valp, valu,nele; FIFOX(nodo*a=0, int b=0, int c=0, int d=0){primo=a; ultimo=a;valp=b;valu=c;nele=d;}};

ostream & operator<<(ostream & OUT, FIFOX& a)
{
	OUT<< '['<<"nele="<<a.nele<<" valp="<<a.valp<<" valu="<<a.valu<<']'<<endl;
	int x=0;
	nodo*z=a.primo;
	while(x<a.nele)
	{OUT<<z->info<<' ';z=z->next; x++;}
	OUT<<endl;
	return OUT;
}

FIFOX push_iter(FIFOX A, nodo*b) {
	if (!A.primo)
		return FIFOX(b, b->info, b->info, 1);
	
	if (b->info < A.valp) {
		b->next = A.primo;
		A.primo = b;
		A.valp = b->info;
		A.nele += 1;
	}
	else if (b->info > A.valu) {
		A.ultimo->next = b;
		A.ultimo = b;
		A.valu = b->info;
		A.nele += 1;
	}
	else {
		nodo* current = A.primo;
		while (current->next->info < b->info) //R= current ha campo info < di b->info e i nodi con campo info < di b->info sono stati superati.
			current = current->next;
		
		b->next = current->next;
		current->next = b;
		
		A.nele += 1;
	}
	
	return A;
}

nodo* rmNode(nodo* list, int z, int & n_ele) {
	if (list->next) {
		if (list->next->info == z) {
			if (list->next->next)
				list->next = list->next->next;
			else
				list->next = 0;
			
			n_ele -= 1;
			return list;
		}
		rmNode(list->next, z, n_ele);
	}
	else return 0;
}

FIFOX deleteX(FIFOX A, int z) {
	if (A.valp > z || A.valu < z || !A.primo)
		return A;
	
	if (A.valp == z) {
		A.primo = A.primo->next;
		A.valp = A.primo->info;
		A.nele -= 1;
	}
	else {
		nodo *result = rmNode(A.primo, z, A.nele);
		
		if (A.valu == z) {
			A.ultimo = result;
			A.valu = result->info;
		}
	}
	
	return A;
}

int main()
{
	int dim1,dim2, x;
	
	cin>>dim1>>dim2;
	FIFOX a;
	while(dim1)
	{
		cin>>x;
		a=push_iter(a,new nodo(x));
		dim1--;
	}
	cout<< a;
	
	while(dim2)
	{
		cin>>x;
		a=deleteX(a,x);
		dim2--;
	}
	cout<<a;
	
	cout<<"end"<<endl;
}

#include<iostream>
#include<malloc.h>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};

int numNodes(nodo* tree) {
    if (!tree) return 0;
    int sx = numNodes(tree->left);
    int dx = numNodes(tree->right);
    
    return sx + dx + 1;
}

nodo* alberobil (nodo* tree, int k) {
	if (!tree)
	    return new nodo(k);
	
	if (numNodes(tree->left) <= numNodes(tree->right))
	    tree->left = alberobil (tree->left, k);
	else
	    tree->right = alberobil (tree->right, k);
	
	return tree;
}

nodo* buildtree(nodo* r, int n) {
	if (n == 0) return r;
	
	int value;
	cin >> value;
	
	return buildtree(alberobil (r, value), n - 1);
}

void stampa_l(nodo* r) {
	if (r) {
		cout << r->info << "(";
		stampa_l (r->left);
		cout << ",";
		stampa_l (r->right);
		cout << ")";
	}
	else
		cout << "_";
}

int main()
{
	int n;
	cin>>n;
	nodo* R=buildtree(0,n);//da fare
	cout<<"start"<<endl;
	
	stampa_l(R); //da fare, vista in classe
	
	cout<<endl<<"end";
}

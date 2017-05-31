#include<iostream>

#include<fstream>
using namespace std;

struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};

int numNodes(nodo* tree) {
    if (!tree) return 0;
    
    return numNodes(tree->left) + numNodes(tree->right) + 1;
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

bool cerca_cam(nodo*r, int k, int y, int*C) {
    if ((k > 0) && (r->info == y)) k--;
    else if ((k == 0) && (r->info == y)) return false;
    
    if (!r->left && !r->right) {
        if (k == 0) {
            *C = -1;
            return true;
        }
    }
    
    if ((r->left) && cerca_cam(r->left, k, y, C + 1)) {
        *C = 0;
        return true;
    }
    
    if ((r->right) && cerca_cam(r->right, k, y, C + 1)) {
        *C = 1;
        return true;
    }
    
    return false;
}

void sc (int* C) {
    if (*C == -1) {
        cout << "fine cammino" << endl;
        return;
    }
    
    cout << *C << " ";
    sc (C + 1);
}

main()
{
  int n, k,y;
  cin>>n;
  nodo* R=buildtree(0,n);//da esercizio 2
  cout<<"start"<<endl;
  stampa_l(R);
   
  cin>>k>>y;
   int C[30];
   bool b=cerca_cam(R,k,y,C); //da fare
   cout<<endl;
   if(b)
     {cout<<"trovato  cammino="; sc(C);} //sc da fare 
   else
    cout<<"nessun cammino con "<<k<<" valori="<<y<<endl;
   cout<<"end";
}

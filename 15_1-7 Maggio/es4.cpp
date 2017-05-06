#include <iostream>

using namespace std;


// PRE = A è un array di int di lunghezza lung >= 1
void ordina(int *A, int lung);
// POST = A è ordinato in modo crescente

int* minimo (int *X, int dim);
void stampa (int *A, int lung);

int main() 
{
    int lung;
    int A[100];
    cin >> lung;
    for(int i = 0; i < lung; i++) { 
        cin >> A[i];
    }
    cout << "start" << endl;
    
    ordina(A, lung);
    
    stampa (A, lung);
    
    cout << "end" << endl;
}

void ordina(int *A, int lung) {
    if (lung == 1) return;
    
    int temp = *A, *min = minimo(A, lung);
    *A = *min;
    *min = temp;
    
    ordina(A+1, lung - 1);
}

int* minimo (int *X, int dim) {
    if (dim == 1) return X;
    
    int* min = minimo(X+1, dim - 1);
    return (*X < *min) ? X : min;
}

void stampa (int *A, int lung) {
    if (lung == 0) return;
    
    cout << *A << " ";
    stampa (A + 1, lung - 1); 
}

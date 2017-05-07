#include <iostream>

using namespace std;

// PRE = i <= j
void inverti(int *A, int i, int j);
// POST = A viene modificato invertendo l’ordine degli elementi nel sottoarray A[i,...,j]
void stampa(int *X, int dim);

int main() 
{
    int lung, primo, ultimo;
    int A[100];
    cin >> lung >> primo >> ultimo;
    for(int i = 0; i < lung; i++) { 
        cin >> A[i];
    }
    cout << "start" << endl;
    inverti (A, primo, ultimo);
    stampa (A, lung);
    cout << "end" << endl;
}

void inverti(int *A, int i, int j) {
    if (i > j) return;
    
    int temp = *(A + i);
    *(A + i) = *(A + j);
    *(A + j) = temp;
    inverti (A, i + 1, j - 1);
}

void stampa(int *X, int dim) {
    if (dim == 0) return;
    
    cout << *X << " ";
    stampa (X + 1, dim - 1);
}

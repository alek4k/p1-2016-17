#include <iostream>

using namespace std;

int main() {
    int length = 10;
    int A[length];
    
    for (int i = 0; i < length; i++)
        cin >> A[i];
        
    for (int j = length - 1; j >= 0; j--)
        cout << A[j] << " ";

    cout << "end" << endl;
}

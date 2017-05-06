#include <iostream>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    int A[n];
    int B[n];
    int temp = 0;
    bool foundB = false;
    
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] == A[j])
            {
                for (int k = 0; k < temp; k++)
                    if (B[k] == A[i])
                        foundB = true;
                
                if (foundB == false)
                    B[temp++] = A[i];
                    
                foundB = false;
            }
        }
    }
    
    if (temp == 0)
        cout << "Tutto regolare" << endl;
    else
    {
        int X[temp];
        for (int i = 0; i < temp; i++)
        {
            for (int k = 0; k < temp; k++)
            {
                for (int j = i + 1; j < temp; j++)
                {
                    if (B[i] > B[j])
                    {
                        int save = B[i];
                        B[i] = B[j];
                        B[j] = save;
                    }
                }
            }
        }
        for (int q = 0; q < temp; q++)
        {
            cout << B[q] << " " << endl;
        }
    }
    
    cout << "end" << endl;
}

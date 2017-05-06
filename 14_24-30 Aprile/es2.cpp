#include<iostream>
#include<string.h>

using namespace std;

struct partialP {
    char letters[50];
    int lung;
};

int numGoodSeq (char *P, int dimP) {
    int count = 0;
    bool newseq = true;

    for (int i = 0; i < dimP; i++) {
        if (P[i] != '*' && newseq) {
            count += 1;
            newseq = false;
        }
        else if (P[i] == '*')
            newseq = true;
    }
    return count;
}

void defineStruct (partialP *current, char *P, int dimP) {
    int count = 0;
    int y = 0;
    bool starfound = false, starfirst = false;

    for (int i = 0; i < dimP; i++) {
        if (P[i] != '*' && starfound) {
            if (starfirst) {
                current[count].letters[y++] = P[i];
                starfirst = false;
            }
            else {
                current[count++].lung = y;
                y = 0;
                current[count].letters[y++] = P[i];
            }
            starfound = false;
        }
        else if (P[i] != '*' && !starfound) {
                current[count].letters[y++] = P[i];
        }
        else if (P[i] == '*') {
            if (i == 0)
                starfirst = true;
            starfound = true;
        }
        if (i == dimP -1)
            current[count].lung = y;
    }
    return;
}

bool findSeq (partialP *seq, char*T, int dimT, int & startpos) {
    int count = 0;
    int startpos2 = startpos;
    startpos = -1;
    for (int i = startpos2; i < dimT && count < seq -> lung; i++) {
        if (T[i] == seq -> letters[count]) {
            count += 1;
            if (startpos == -1)
                startpos = i;
        }
        else
        {
            count = 0;
            startpos = -1;
        }
    }
    return (seq -> lung == count);
}

bool match(char* T, int dimT, char* P, int dimP, int* X, int &num) {
    num = numGoodSeq (P, dimP);
    if (num == 0)
        return true;

    partialP portion[num];
    defineStruct(portion, P, dimP);

    int startpos = 0, y = 0, lastEndPos = 0;
    for (int i = 0; i < num; i++) {
        if (!findSeq (&portion[i], T, dimT, startpos))
            return false;

        X[y++] = startpos - lastEndPos;
        X[y++] = portion[i].lung;
        lastEndPos = startpos + portion[i].lung;
        startpos += 1;
    }
    return true;
}

void stampa(char*P, int dimP, int*X, int num) {
    partialP portion[num];
    defineStruct(portion, P, dimP);
        
    int pos = 0;
    for(int i = 0; i < num; i++) {
        if (X[pos] != 0) {
            if (i != 0)
                cout << endl;
            cout << "dopo " << X[pos] << " elementi " << endl << "troviamo ";
        }
        pos += 1;
        for (int j = 0; j < X[pos]; j++)
            cout << portion[i].letters[j];
        pos += 1;
    }
    cout << endl;
}

main()
{
  char T[400], P[50];
  char c;
  int i=0;
  cin >> c;
  while (c != '.')
    {P[i]=c; i++; cin>>c;}
  int dimP=i;
  i=0;
  cin >> c;
  while (c != '.')
    {T[i]=c; i++; cin>>c;}
  cout<<"start"<<endl;
  int dimT=i;
  int X[100];
 
  int num=0;
  bool m=match(T,dimT,P,dimP,X,num);
 
   if(!m)
    cout<<"nessun match"<<endl;
   else
     {
       for(int i=0; i<num; i=i+1)
	 cout<<X[2*i]<<' '<<X[2*i+1]<<endl;
       stampa(P,dimP,X,num);
     }
   cout<<"end"<<endl;
}

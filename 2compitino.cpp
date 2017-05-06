#include <iostream>
#include <string.h>
using namespace std;

bool match(char *T, int lungT, char *P, int lungP, int & lungmatch)
{	
	if (*T != *P)
		return false;
	
	int count_match = 0;
	for (int i = 0; i < lungT && count_match < lungP; i++) {
	/* R = (1 <= i <= lungT) && (0 <= count_match <= lungP) &&
	 * (P[0] = T[0] && P[count_match - 1] = T[lungmatch])
	 */ 
		if(P[count_match] == T[i]) {
			count_match += 1;
			lungmatch = i + 1;
		}
	}
	
	return (count_match == lungP);
}

int main()
{
	char P[100] = "abba";
	int lungP = strlen(P);
	
	char T[400] = "as bafba tesabbat code abbajiy";
	int lungT = strlen(T);
        
    int lung, minLung = 0, bestIndex = -1;
    
    cout << "start" << endl;
    
    for (int i = 0; i < lungT - lungP + 1; i++) {
		if (match (T + i, lungT, P, lungP, lung))
			if (lung <= minLung || minLung == 0) {
				minLung = lung;
				bestIndex = i;
			}
	}

	if (bestIndex == -1)
		cout << "Nessun match trovato." << endl << "end";
	else
		cout << "Miglior match comincia alla posizione: " << bestIndex << " ed è di lunghezza: " << minLung << endl << "end";    
}

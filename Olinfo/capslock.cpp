#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000

void aggiusta(int N, char S[]) {
    for (int i=0; i<N; i++ ){
    	if (S[i] >= 65 && S[i] <= 90){
    		S[i] = S[i]+32;
		}
		else if (S[i] >= 97 && S[i] <= 122){
			S[i] = S[i]-32;
		}
	}
	for (int i=0; i<N; i++){
		cout << S[i]; 
	}
}

char S[MAXN + 5]; // Maggiore di MAXN per contenere newline e null

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d\n", &N));
    assert(fgets(S, MAXN + 5, fr) == S);
    S[N] = 0;

    aggiusta(N, S);
    fprintf(fw, "%s\n", S);
    fclose(fr);
    fclose(fw);
    return 0;
}
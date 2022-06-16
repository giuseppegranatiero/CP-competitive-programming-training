#include <bits/stdc++.h>

using namespace std;
#define MAXN 10000

int interroga(int N, int K, int D[]) {
	int N2 = N-(K-1);
	int differenze[N2];
    // ordinare l'array
    sort(D, D + N);
    // aggiungere le differenze
    for (int i=0; i<N2; i++){
    	differenze[i]=-(D[i]-D[i+(K-1)]);
	}
    sort(differenze, differenze + N2);
    return differenze[0];
}

int D[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(2 == fscanf(fr, "%d%d", &N, &K));
    for (i = 0; i < N; i++)
        assert(1 == fscanf(fr, "%d", &D[i]));

    fprintf(fw, "%d\n", interroga(N, K, D));
    fclose(fr);
    fclose(fw);
    return 0;
}
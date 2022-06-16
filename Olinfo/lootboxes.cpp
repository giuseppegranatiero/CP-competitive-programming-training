#include <stdio.h>
#include <assert.h>
#define MAXN 5000

// input data
int N, X, i;
int P[MAXN], Q[MAXN];
int r[10001];
int rold[10001];
int main() {
//  uncomment the following lines if you want to read/write from files
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &X));
    for(i=0; i<N; i++)
        assert(2 == scanf("%d %d", &P[i], &Q[i]));

    for (int i=0; i<N; i++){
    	for (int j=Q[i]; j<=X; j++){
    		if (P[i]+rold[j-Q[i]] > r[j]) r[j]=P[i]+rold[j-Q[i]];
		}
		for (int j=Q[i]; j<=X; j++){
			rold[j] = r[j];
		}
	}
    printf("%d\n", r[X]); // print the result
    return 0;
}
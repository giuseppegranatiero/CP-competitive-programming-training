#include <stdio.h>
#include <assert.h>

// constraints
#define MAXM 200000

// input data
int N, M, i;
int A, B, W, bal[MAXM];


int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d%d", &N, &M));
    for(i=0; i<M; i++){
    	assert(3 == scanf("%d%d%d", &A, &B, &W));
    	bal[A] -= W;
    	bal[B] += W;
	}
        

    // insert your code here
    int n_ris = 0;
    
    for(i=1; i<N;i++){
    	if(bal[i] != 0) n_ris++;
	}
    printf("%d\n", n_ris);
    
    for(i=1; i<N;i++){
    	if(bal[i] > 0) printf("%d %d %d\n", i, 0, bal[i]);
    	else if(bal[i]<0) printf("%d %d %d\n", 0, i, -bal[i]);
	}
 // print the result
    return 0;
}
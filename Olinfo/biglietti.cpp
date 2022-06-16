#include <stdio.h>
#include <assert.h>

int compra(int N, int M, int A, int B) {
    int s=0;
    int q=0;
    q=B/M;
	while(N>0){
		
		if (N<M){
			if (B<A*N){
				s+=B;
			} else {
				s+=A*N;
			}
			N=0;
		}else {
			if(q<A){
				s+=B;
				N=N-M;
			} else {
				s+=A*N;
				N=0;
				
			}
		}
	}
    
return s;
}

int main() {
    FILE *fr, *fw;
    int N, M, A, B;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(fw, "%d\n", compra(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
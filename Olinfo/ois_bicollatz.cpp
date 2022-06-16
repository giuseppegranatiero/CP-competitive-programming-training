#include <stdio.h>
#include <assert.h>

int bicollatz(long int a, long int b) {
    long int ris=0;
    int a1=a;
    int b1=b;
	while (a>1 || b>1){
	    ris++;
		if (a%2==0 && b%2==0){
			a/=2;
			b/=2;
		}
		else if (a%2!=0 && b&2!=0){
			a=a*3+1;
			b=b*3+1;
		} 
		else{
			if (a%2==0) b+=3;
			else a+=3;
		}
		if (ris >= 10000){
		    ris=-1;
		    break;
		}
		
	}
	return ris;
}


int main() {
    FILE *fr, *fw;
    int A, B;
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &A, &B));

    fprintf(fw, "%d\n", bicollatz(A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
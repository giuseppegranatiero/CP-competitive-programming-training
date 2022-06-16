#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

int main(){
    assert(freopen("input.txt", "r", stdin)!=NULL);
    assert(freopen("output.txt", "w", stdout)!=NULL);
	long long int N, max, S;
	cin >> N;
	max=0;
	long long int array[N];
	for (int x=0; x<N; x++){
		cin >> S;
		array[x]=S;
	}
	sort(array, array+N);
	for (int x=N-2; x>=0; x--){
		int somma=array[N-1]+array[x];
		if (somma%2==0){
		    max=somma;
		    break;}
	}
	for (int x=N-3; x>=0; x--){
	    int somma=array[N-2]+array[x];
	    if (somma%2==0&&somma>max){
	        max=somma;
		    break;}
	}

	if (max==0) max=-1;
	cout << max;
	return 0;
}
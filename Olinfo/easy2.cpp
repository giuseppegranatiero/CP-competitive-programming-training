#include <iostream>
#include <cassert>
using namespace std;

int main(){
    assert(freopen("input.txt", "r", stdin)!=NULL);
    assert(freopen("output.txt", "w", stdout)!=NULL);
	int N, max, ai, bi;
	cin >> N;
	max = 0;
	for (int x=0; x<N; x++){
		cin >> ai >> bi;
		int somma = ai+bi;
		if (somma>max && somma%2==0) max=somma;
	}
	if (max==0) max=-1;
	cout << max;
	return 0;
}

#include <iostream>
#include <cassert>
using namespace std;

int main(){
    assert(freopen("input.txt", "r", stdin)!= NULL);
    assert(freopen("output.txt", "w", stdout)!= NULL);
	long long int M, N, P, C;
	cin >> N >> M;
	long long int prices[N];
	long long int compens[N];
	for (int x=0; x<N; x++){
		cin >> P;
		prices[x]=P;
	}
	for (int x=0; x<N; x++){
		cin >> C;
		compens[x]=C;
	}
	int nprices=0;
	for (int x=0; x<N; x++){
		if (M<prices[x]) M+=compens[x];
		else{
			M-=prices[x];
			nprices++;
		}
	}
	cout << nprices << " " << M;
	return 0;
}

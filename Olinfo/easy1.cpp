#include <iostream>
#include <cassert>
using namespace std;

int main(){
    assert(freopen("input.txt", "r", stdin)!=NULL);
    assert(freopen("output.txt", "w", stdout)!=NULL);
	int N, max, S;
	cin >> N;
	max = -1000;
	for (int x=0; x<N; x++){
		cin >> S;
		if (S>max) max=S;
	}
	cout << max;
	return 0;
}

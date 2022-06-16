#include <iostream>
#include <cassert>
using namespace std;

int main(){
	assert(freopen("input.txt", "r", stdin)!=NULL);
	assert(freopen("output.txt", "w", stdout)!=NULL);
	int N;
	cin >> N;
	while(N%10!=0) N=N*(N%10-1)/2;
	cout << N;
	return 0;
}
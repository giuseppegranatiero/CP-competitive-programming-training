#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	assert(freopen("input.txt", "r", stdin)!=NULL);
	assert(freopen("output.txt", "w", stdout)!=NULL);
	int n, l=1;
	cin >> n;
	while (n!=1){
		if (n%2==0) n/=2;
		else n=n*3+1;
		l++;
	}
	cout << l;
}
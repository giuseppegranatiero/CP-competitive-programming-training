#include <bits/stdc++.h>

using namespace std;

int main(){
	assert(freopen("input.txt","r",stdin)!=NULL);
    assert(freopen("output.txt","w",stdout)!=NULL);
	int n, i;
	cin >> n;
	int v[n];
	for (i=0; i<n; i++){
		cin >> v[i];
	}
	for (i=1; i<n; i++){
		if(v[i]==-1){
			v[i]=v[i-1];
		}
	}
	int somma=0;
	for (i=0; i<n; i++){
		somma+=v[i];
	}
	cout << somma;
	return 0;
}
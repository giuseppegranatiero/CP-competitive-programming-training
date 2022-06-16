#include <bits/stdc++.h>
using namespace std;

int main(){
	assert(freopen("input.txt","r",stdin)!=NULL);
    assert(freopen("output.txt","w",stdout)!=NULL);
	long long int n, m, i, somman=0;
	cin >> n >> m;
	long long int kids[n];
	for (i=0; i<n; i++){
		cin >> kids[i];
		somman += kids[i];
	}
	m = m%somman;
	if (m==0) cout << n-1;
	else{
		i = 0;
		while(m>0){
			m-=kids[i];
			i++;
		}
		cout << --i;
	}
}


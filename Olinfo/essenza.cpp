#include <bits/stdc++.h>
using namespace std;

int prezzi[1000];
int maxn = 0;
int n, k;

void max(int i, int b){
	for (int j=i; j<=b&& j<n; j++){
		if(prezzi[j]-prezzi[i]>maxn) maxn = prezzi[j]-prezzi[i];
	}
}

int main(){
	assert(freopen("input.txt","r",stdin)!=NULL);
    assert(freopen("output.txt","w",stdout)!=NULL);
	
	cin >> k >> n;
	for (int i=0; i<n; i++){
		cin >> prezzi[i];
	}
	for (int i=0; i<n; i++){
		max(i, i+k);
	}
	cout << maxn;
}
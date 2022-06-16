#include <bits/stdc++.h>
using namespace std;

int main(){
	assert(freopen("input.txt","r",stdin)!=NULL);
    assert(freopen("output.txt","w",stdout)!=NULL);
    int fibonacci[31];
	int n;
	string ris = "";
	cin >> n;
	fibonacci[0] =1;
	fibonacci[1] =1;
	int i=1;
	// riempio fibonacci
	while (fibonacci[i]<n){
		i++;
		fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
	}
	// trovo codifica
	i-=1;
	// tolgo 1 perchè l'ultimo elemento sarà sempre più grande o uguale
	while(n!=0){
		if (n-fibonacci[i] < 0) ris = "0" + ris;
		else{
			n-=fibonacci[i];
			//cout << fibonacci[i] << " ";
			ris = "1" + ris;
		}
		--i;	
	}
	for(int j=i; j>=0; j--){
		ris = "0" + ris;
	}
	cout << ris;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int azioni[n];
	for(int i=0; i<n; i++){
		cin >> azioni[i];
	}
	int ris = 0;
	for(int i=1; i<n; i++){
		if (abs(azioni[i]-azioni[i-1])>ris) ris = abs(azioni[i]-azioni[i-1]);
	}
	cout << ris;
}
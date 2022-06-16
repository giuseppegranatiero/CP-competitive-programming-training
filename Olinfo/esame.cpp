#include <bits/stdc++.h>
using namespace std;

int n;

	
int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	cin >> n;
    int ris[n+1];
    int ris2[n+1];
    int voti[n];

	for(int i=0; i<n; i++){
		cin >> voti[i];
	}
	ris[0] = 0;
	ris[1] = voti[0];
	
	for(int i=2; i<n; ++i){
		ris[i] = max(voti[i-1] + ris[i-2], ris[i-1]);	
	}
	
	ris2[0] = 0;
	ris2[1] = 0;
	for(int i=2; i<=n; ++i){
		ris2[i] = max(voti[i-1] + ris2[i-2], ris2[i-1]);	
	}
	
	/*cout << endl;
	for(int i=0; i<=n; ++i){
		cout << ris[i] << " ";
	}*/
	
	cout << max(ris[n-1], ris2[n]);
}
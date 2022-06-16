#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int stazioni[n];
	for(int i=0; i<n; i++){
		cin >> stazioni[i];
	}
	int ris;
	for(int i=0; i<n; i++){
		int gas_res = stazioni[i];
		int j = i+1;
		while(gas_res-10 >= 0){
			if(j==n) j = 0;
			gas_res -= 10;
			gas_res += stazioni[j];
			j++;
			if(j==i){
				ris = i;
				break;
			} 
			//cout << gas_res << endl;
		}
	}
	cout << ris+1;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	int vini[n];
	int subsequence[n];
	for (int i=0; i<n; ++i){
		cin >> vini[i];
		subsequence[i] = 1;
	}
	for (int i=n-1; i>=0; --i){
		for (int j=n-1; j>i+1; j--){
			if (vini[i]<=vini[j] && subsequence[j]>=subsequence[i]){
				subsequence[i] = subsequence[j] +1;
				j--;
			}
		}
	}
	int max = 1;
	for (int i=0; i<n; i++){
		if (subsequence[i]>max) max = subsequence[i];
	}
	cout << max;
}
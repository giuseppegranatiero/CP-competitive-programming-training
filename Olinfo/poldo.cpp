#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	assert(freopen("input.txt", "r", stdin)!=NULL);
	assert(freopen("output.txt", "w", stdout)!=NULL);
	
	
	
	
	
	int n, num;
	cin >> n;
	vector<int> panini_val(n);
	int panini[n];
	for (int i=0; i<n; i++){
		cin >> panini[i];
	}
	int max = -1;
	for (int i=n-1; i>=0; i--){
		num = 1;
		for (int y=i+1; y<n; y++){
			if(panini[y]<panini[i] && panini_val[y]>= num){
				num=panini_val[y]+1;
				}
			}
		if (num > max) max = num;
		panini_val[i]=num;
	}
	cout << max;
}
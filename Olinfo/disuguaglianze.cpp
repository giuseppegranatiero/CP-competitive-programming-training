#include <bits/stdc++.h>
using namespace std;

int main(){
	assert(freopen("input.txt","r",stdin)!=NULL);
    assert(freopen("output.txt","w",stdout)!=NULL);
	int n;
	cin >> n;
	char segno[n];
	int min = 1;
	int max = n;
	for (int i=0; i<n-1; i++){
		cin >> segno[i];
	}
	for (int i=0; i<n-1; i++){
		if (segno[i] == '<'){
			cout << min << " ";
			min++;
		}
		else{
			cout << max << " ";
			max--;
		}
	}
	if (segno[n-2] == '<'){
		cout << max;
	}
	else cout << min;
}
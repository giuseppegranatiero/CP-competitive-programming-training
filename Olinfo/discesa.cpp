#include <bits/stdc++.h>
using namespace std;

int main(){
    assert(freopen("input.txt","r",stdin)!=NULL);
    assert(freopen("output.txt","w",stdout)!=NULL);
	int n;
	cin >> n;
	int triangle[n][n];
	for (int i=0; i<n; i++){
		for (int k=0; k<i+1; k++){
			cin >> triangle[i][k];
		}
		for (int k=0; k<n-i; k++){
			triangle[i][k+i+1] = 0;
		}
	}
	for (int i=n-1; i>0; i--){
		for (int k=i; k>0; k--){
			if (triangle[i][k-1]>triangle[i][k]){
				triangle[i-1][k-1] += triangle[i][k-1];
			}
			else{
				triangle[i-1][k-1] += triangle[i][k];
			}
		}
	}
	cout << triangle[0][0];		
}
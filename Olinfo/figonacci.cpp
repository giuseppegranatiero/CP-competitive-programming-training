#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int n, m;
	vector<ll int> figonacci;
	cin >> n >> m;
	figonacci.resize(n+1, 0);
	figonacci[0] = -1;
	figonacci[1] = 0;
	int sum = -1;
	for(int i=2; i<=n; i++){
		figonacci[i] = ((i-1)*figonacci[i-1]%m-sum%m)%m;
		sum = (sum%m + figonacci[i-1]%m)%m;
		figonacci[i] = (figonacci[i]%m + m)%m;
	}
	cout << figonacci[n];	
}
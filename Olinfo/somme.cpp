#include <bits/stdc++.h>
using namespace std;

struct comp{
	bool operator()(int a, int b){
		if (a>b) return true;
		else return false;
	}
};
int main(){
	assert(freopen("input.txt","r",stdin)!=NULL);
    assert(freopen("output.txt","w",stdout)!=NULL);
    priority_queue<int, vector<int>, comp> coda;
    int n, costo, costotot=0;
    cin >> n;
    for (int i=0; i<n; i++){
    	cin >> costo;
    	coda.push(costo);
	}
	int somma = 0;
	while (!coda.empty()){
		int val1 = coda.top();
		coda.pop();
		if (!coda.empty()){
		    int val2 = coda.top();
    		coda.pop();
    		somma = val1+val2;
    		costotot+= somma;
    		coda.push(somma);
		}
	}
	cout << costotot;
}
#include <bits/stdc++.h>

using namespace std;

// input data
int N, M, E, ris=0;

int main() {
//  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N >> M >> E;

    for (int i=M; i<=N; i++){
    	if(E%i>ris) ris=E%i;
	}

    cout << ris << endl; // print the result
    return 0;
}
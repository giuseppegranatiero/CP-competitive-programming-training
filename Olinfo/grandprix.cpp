#include <bits/stdc++.h>
using namespace std;

vector<int> classifica;

void scambia(int supera, int superato){
	vector<int>::iterator itr = find(classifica.begin(), classifica.end(), supera);
	int index_supera = distance(classifica.begin(), itr);
	itr = find(classifica.begin(), classifica.end(), superato);
	int index_superato = distance(classifica.begin(), itr);
	classifica[index_superato] = supera;
	classifica[index_supera] = superato;
}

int main(){
	assert(freopen("input.txt","r",stdin)!=NULL);
    assert(freopen("output.txt","w",stdout)!=NULL);
	int n, k, supera, superato, car;
	cin >> n >> k;
	for (int i=0; i<n; i++){
		cin >> car;
		classifica.push_back(car);
	}
	for (int i=0; i<k; i++){
		cin >> supera >> superato;
		scambia(supera, superato);
	}
	cout << classifica[0];
    return 0;
}
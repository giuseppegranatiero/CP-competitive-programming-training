#include <bits/stdc++.h>
using namespace std;

struct turno{
	int inizio;
	int fine;
};
turno turni[50];

bool cmp(turno a, turno b){
	return a.inizio < b.inizio;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    assert(freopen("input.txt","r",stdin)!=NULL);
    assert(freopen("output.txt","w",stdout)!=NULL);
	int n, k;
	cin >> n >> k;
	for (int i=0; i<k; i++){
		cin >> turni[i].inizio >> turni[i].fine;
	}
	sort(turni, turni+k, cmp);
	int i=0;
	int fine=-1;
	int max=0;
	int counter=0;
	while(i<k){
		while(turni[i].inizio <= fine+1 && i<k){
			if (turni[i].fine>max) max = turni[i].fine;
			i++;
		}
		if (max > fine){
			fine = max;
			counter++;
		}
	}
	cout << counter;
}
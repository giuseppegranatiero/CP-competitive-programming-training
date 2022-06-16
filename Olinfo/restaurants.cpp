#include <bits/stdc++.h>
using namespace std;

struct ristoratore{
	int id;
	int points;
};

ristoratore ristoratori[101];

bool cmp(ristoratore a, ristoratore b){
	return a.points>b.points;
}

int main(){
	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
	int n, vote;
	cin >> n;
	for (int i=0; i<n; i++){
		ristoratori[i].id = i+1;
		for (int j=0; j<=n; j++){
			cin >> vote;
			ristoratori[i].points+=vote;
		}
		ristoratori[i].points-=1;
		sort(ristoratori, ristoratori+i+1, cmp);
		//cout << getIndex(rank, real-1)+1 << endl;
		cout << ristoratori[0].id << endl;
	}
}
#include <bits/stdc++.h>
using namespace std;

struct svincolo{
	int nodo=0;
	int luce=50001;
};

svincolo svincoli[50001];
int visti[50001];
int last_node;

int path(int nodo, int count, int end){
	// caso base
	if (nodo == end) return count;
	if (visti[nodo] == 1){
		//last_node = nodo;
		return -1;
	}
	// caso generale
	visti[nodo] = 1;
	path(svincoli[nodo].nodo, count+=1, end);	
}

int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int n, m, h, s, nodo, adj, luce;
	cin >> n >> m >> h >> s;
	for (int i=0; i<m; ++i){
		cin >> nodo >> adj >> luce;
		if (luce < svincoli[nodo].luce){
			svincoli[nodo].nodo = adj;
			svincoli[nodo].luce = luce;
		}
		if (luce < svincoli[adj].luce){
			svincoli[adj].nodo = nodo;
			svincoli[adj].luce = luce;
		}
	}
	if (h==s) cout << 0;
	else{
		visti[0] = 1;
		for(int i=1; i<=n; i++){
			visti[i] = 0;
		}
		/*cout << endl;
		for (int i=1; i<=n; i++){
			cout << i << " " << svincoli[i].nodo << " " << svincoli[i].luce << endl;
		}
		int r = path(h, 0, s);
		if (last_node == s) cout << r;
		else cout << -1;*/
		int r = path(h, 0, s);
		cout << r;
	}
}
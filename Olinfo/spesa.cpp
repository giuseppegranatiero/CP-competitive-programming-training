#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

vector<int> adj[10001];
int supermercati[10001];
int distanza[10001];
int distanza2[10001];
int a, b, n, m, k;

int BFS(int from){
	bool visti[10001]= {false};
	queue<pair<int,int>> q;
	q.push(make_pair(from, 0));
	
	visti[from] = true;
	
	while(!q.empty()){
		
		int nodo = q.front().first;
		int dist = q.front().second;
		//cout << nodo << " -> " << dist << endl;
		distanza[nodo] = dist;
		q.pop();
		
		for(int i = 0; i < adj[nodo].size(); i++){
			int next = adj[nodo][i];
			if(visti[next])continue;
            visti[next] = true;
			q.push(make_pair(next, dist+1));
		}
	}
}

int BFS2(int from){
	bool visti[10001]= {false};
	queue<pair<int,int>> q;
	q.push(make_pair(from, 0));
	
	visti[from] = true;
	
	while(!q.empty()){
		
		int nodo = q.front().first;
		int dist = q.front().second;
		//cout << nodo << " -> " << dist << endl;
		distanza2[nodo] = dist;
		q.pop();
		
		for(int i = 0; i < adj[nodo].size(); i++){
			int next = adj[nodo][i];
			if(visti[next])continue;
            visti[next] = true;
			q.push(make_pair(next, dist+1));
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	cin >> n >> m >> k;
	for(int i=0; i<k; i++){
		cin >> supermercati[i];
	}
	for (int i=0; i<m; ++i){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ris = INF;
	BFS(1);
	BFS2(n);
	for(int i=0; i<k; i++){
		if (distanza[supermercati[i]] + distanza2[supermercati[i]] < ris){
			ris = distanza[supermercati[i]] + distanza2[supermercati[i]];
		}
	}
	cout << ris;
}
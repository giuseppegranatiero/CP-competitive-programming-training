#include <bits/stdc++.h>
#define INF 1000001
using namespace std;

vector<pair<int,int>> adj[10001];
long long int dist[10001];
int visto[10001];
int a, b, start, endx, n, m, p, A, B;

struct comp {
    bool operator() (pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};

priority_queue<pair<int,int>, vector<pair<int,int>>, comp> q;

void dijkstra(){
	
	dist[start] = 0;
	q.push(make_pair(start,0));
	
	while(!q.empty()){
		int parent_node = q.top().first;
		//cout << parent_node << " " << q.top().second << " "<< dist[parent_node] << endl;
		q.pop();
		
		
		if (parent_node == endx) return;
		
		for (int i=0; i<adj[parent_node].size(); ++i){
			int node = adj[parent_node][i].first;
			if (visto[node]==0 && dist[parent_node]+adj[parent_node][i].second < dist[node]){
				dist[node] = dist[parent_node]+adj[parent_node][i].second;
				q.push(make_pair(node, dist[node]));
			}
		}
		visto[parent_node] = 1;
	}
	
}

int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	cin >> n >> A >> B;
	start = 1;
	endx = n;
	for (int i=0; i<A; ++i){
		cin >> a >> b;
		adj[a].push_back(make_pair(b, 0));
		adj[b].push_back(make_pair(a, 0));
	}
	for (int i=0; i<B; ++i){
		cin >> a >> b;
		adj[a].push_back(make_pair(b, 1));
		adj[b].push_back(make_pair(a, 1));
	}
	for (int i=0; i<=n; i++){
		dist[i] = INF;
	}
	
	dijkstra();
	
	/*for (int i=1; i<=n; ++i){
		cout << i << " " << dist[i] << endl ;
	}*/
	cout << dist[endx];
}
#include <bits/stdc++.h>
#define MAXN 31
using namespace std;

vector<pair<int,int>> adj[MAXN];
int ris=0;
int aria[MAXN];
int dist[MAXN];
int visto[MAXN];

struct comp {
    bool operator() (pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};

priority_queue<pair<int,int>, vector<pair<int,int>>, comp> q;

int dijkstra(int start, int end){
	
	dist[start] = 0;
	q.push(make_pair(start,0));
	
	while(!q.empty()){
		int parent_node = q.top().first;
		int parent_dist = q.top().second;
		//cout << parent_node << " "<< dist[parent_node] << endl;
		if (parent_node == end) return q.top().second;

		q.pop();
		ris+=dist[parent_node];
		
		
		for (int i=0; i<adj[parent_node].size(); ++i){
			int node = adj[parent_node][i].first;
			if (aria[parent_node] == 1){
				if (visto[node]==0 && adj[parent_node][i].second <= 20){
					//dist[node] = dist[parent_node]+adj[parent_node][i].second;
					dist[node] = adj[parent_node][i].second;
					q.push(make_pair(node, parent_dist + dist[node]));
				}
			}
			else{
				if (visto[node]==0 && dist[parent_node]+adj[parent_node][i].second <= 20){
					//dist[node] = dist[parent_node]+adj[parent_node][i].second;
					dist[node] = adj[parent_node][i].second;
					q.push(make_pair(node, parent_dist + dist[node]));
				}
			}
		}
		visto[parent_node] = 1;
	}
	//ris = -1;
	return -1;
}

int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int n, m, c, k, sacca, a, b, p;
	cin >> n >> m >> c >> k;
	for(int i=0; i<k; ++i){
		cin >> sacca;
		aria[sacca] = 1;
	}
	for(int i=0; i<m; i++){
		cin >> a >> b >> p;
		adj[a].push_back(make_pair(b,p));
		adj[b].push_back(make_pair(a,p));
	}
	for (int i=0; i<=n; i++){
		dist[i] = INT_MAX;
	}
	cout << dijkstra(1, c);
	//cout << ris;
}
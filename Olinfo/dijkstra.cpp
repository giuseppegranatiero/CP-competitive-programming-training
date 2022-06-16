#include <bits/stdc++.h>
#define INF LLONG_MAX
using namespace std;

vector<pair<int,long long int>> adj[10002];
long long int dist[10002];
int visto[10002];
long long int a, b, start, endx, n, m, p;

struct comp {
    bool operator() (pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};


priority_queue<pair<int,int>, vector<pair<int,int>>, comp> q;

void dijkstra(){

    while(!q.empty()){
        long long int parent_node = q.top().first;
        q.pop();

        if (parent_node == endx) return;

        for (int i=0; i<adj[parent_node].size(); ++i){
            long long int node = adj[parent_node][i].first;
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
    cin >> n >> m;
    cin >> start >> endx;
    for (int i=0; i<m; ++i){
        cin >> a >> b >> p;
        adj[a].push_back(make_pair(b, p));
    }

    for (int i=0; i<=n; i++){
        dist[i] = INF;
    }
    dist[start] = 0;

    q.push(make_pair(start,0));
    dijkstra();

    cout << dist[endx];
}
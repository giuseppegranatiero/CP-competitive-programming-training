#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;

vector<pair<int,int>> adj[MAXN];
int ris[MAXN], visto[MAXN];
int n, a;

int dijkstra(){
    for(int i=0; i<n; i++){
        ris[i] = MAXN+1;
    }
    //                 dist  node
    priority_queue<pair<int, int>> pq;
    ris[0] = 0;
    pq.push(make_pair(0, 0));
    while(!pq.empty()){
        int node = pq.top().second;
        int dist = -pq.top().first;
        if(node == n-1) return dist;
        pq.pop();
        visto[node] = 1;
        for(auto j: adj[node]){
            if(visto[j.first]==0 && dist+j.second < ris[j.first]){
                ris[j.first] = dist+j.second;
                pq.push(make_pair(-ris[j.first], j.first));
            }
        }
    }
    //return ris[n-1];
}

int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> a;
        adj[i].push_back(make_pair(a, 0));
        if(a != i+1 && i < n-1){
            adj[i].push_back(make_pair(i+1, 1));
        }
        if(a != i-1 && i > 0){
            adj[i].push_back(make_pair(i-1, 1));
        }
    }
    cout << dijkstra();
}
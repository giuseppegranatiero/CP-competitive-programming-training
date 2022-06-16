#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

vector<int> adj[MAXN], rev[MAXN];
stack<int> s;
vector<int> visited;
int n, a, temp_dim = 0, ris = 0;

void dfs(int node){
    visited[node] = 1;
    for(int j: adj[node]){
        if(visited[j] == 0) dfs(j);
    }
    s.push(node);
}

void dfs2(int node){
    //cout << node << " ";
    temp_dim++;
    visited[node] = 1;
    for(int j: rev[node]){
        if(visited[j] == 0){
            dfs2(j);
        } 
    }
}

void kosaraju(){
    visited.resize(n, 0);
    for(int i=0; i<n; ++i){
        if(visited[i]==0) dfs(i);
    }
    visited.clear();
    visited.resize(n, 0);
    while(!s.empty()){
        int node = s.top();
        s.pop();
        if(visited[node] == 0){
            dfs2(node);
            ris = max(ris, temp_dim);
            temp_dim = 0;
            //cout << endl;
        } 
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> a;
        adj[i].push_back(a);
        rev[a].push_back(i);
    }  
    kosaraju();
    cout << ris;
}
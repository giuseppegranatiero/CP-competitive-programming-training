#include <bits/stdc++.h>
#define ll long long
#define MAXN 10000
using namespace std;

int parent_node[MAXN];
int h[MAXN];

void MAKE_SET(int x){
    parent_node[x] = x;
    h[x] = 0;
}

int FIND(int x){
    if (x == parent_node[x]) return x;
    return parent_node[x] = FIND(parent_node[x]); // path compression
}

void UNION(int x, int y){  // link by rank (h)
    int a = FIND(x);
    int b = FIND(y);
    if(a != b){               
        if (h[a] < h[b]){
            parent_node[a] = b;
        }
        else{
            parent_node[b] = a;
            if(h[a] == h[b]){
                h[a]++;
            }
        }
    }
}

struct arco{
    int a, b;
    ll int w;
};

vector<arco> A;

bool comp(arco d, arco s){
    return d.w < s.w;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, sol=0;
    vector<arco> archi_sol;
    cin >> n >> m;
    A.resize(m);
    for(int i=0; i<m; i++){
        cin >> A[i].a >> A[i].b >> A[i].w;
    }
    sort(A.begin(), A.end(), comp);
    for(int i=0; i<n; i++) MAKE_SET(i);
    for(int i=0; i<m; i++){
        if(FIND(A[i].a) != FIND(A[i].b)){
            UNION(A[i].a, A[i].b);
            sol += A[i].w;
            archi_sol.push_back(A[i]);
        }
    }
    cout << sol << endl;
    for(int i=0; i<archi_sol.size(); i++){
        cout << archi_sol[i].a << " " << archi_sol[i].b << endl;
    }
}
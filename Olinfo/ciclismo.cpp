#include <bits/stdc++.h>
#define MAXN 10000
#define MAXM 100000
using namespace std;

int H[MAXN], A, B;
vector<int> adj[MAXN];
int visti[MAXN];

int DFS(int nodo, int da){
	//caso base
	if(visti[nodo]==1){
		return nodo;
	} 
	//caso generale 
	visti[nodo]=1;
	int min = -1;
	for(int i=0; i<adj[nodo].size(); i++){			
		int next = adj[nodo][i];
		if ((H[next]<H[min] || min==-1)&& adj[nodo][i]!=da ){
			min = next;
		} 
	}
	if(min == -1) return nodo;
	DFS(min, nodo);
}

int main() {
	assert(freopen("input.txt","r",stdin)!=NULL);
    assert(freopen("output.txt","w",stdout)!=NULL);
    int N, M, i;
    cin >> N >> M;
    for(i=0; i<N; i++)
        cin >> H[i];
    for(i=0; i<M; i++){
    	cin >> A >> B;
    	adj[A].push_back(B);
    	adj[B].push_back(A);
	}

    int r = DFS(0, -1);
    cout << r;
    //fclose(fr);
    //fclose(fw);
    return 0;
}
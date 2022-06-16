#include<bits/stdc++.h>
#define ll long long 
#define MAXN 5001
using namespace std;

int arr[MAXN];
ll dp[MAXN][MAXN];

int f(int i, int j){
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    ll op1 = arr[i] + min(f(i+2,j), f(i+1,j-1) );
    ll op2 = arr[j] + min(f(i+1,j-1), f(i,j-2) );

    return dp[i][j] = max(op1,op2);

}

int contentezza(int N, int V[]){
    for(int i=0; i<N; i++){
        arr[i] = V[i];
    }
    memset(dp, -1, sizeof(dp));
    return f(0, N-1);
}
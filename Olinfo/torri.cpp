#include <bits/stdc++.h>
using namespace std;

int main(){
    assert(freopen("input.txt","r",stdin)!=NULL);
    assert(freopen("output.txt","w",stdout)!=NULL);
    int n, tot=0;
    cin >> n;
    int h[n], c[n];
    for(int i=n-1; i>-1; --i){
        cin >> h[i] >> c[i];
        tot += c[i];
    }
    int dp[n], mas;
    dp[0] = c[0];
    for(int i=1; i<n; i++){
        mas = 0;
        for(int j=0; j<i; j++){
            if(h[j] < h[i]) mas = max(dp[j], mas);
        }
        dp[i] = mas+c[i];
    }
    mas = 0;
    for(int i=0; i<n; i++){
        mas = max(mas, dp[i]);
    }
    cout << tot-mas;
}
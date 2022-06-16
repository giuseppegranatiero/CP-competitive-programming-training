#include <bits/stdc++.h>
using namespace std;

struct missione{
    int durata;
    int scadenza;
};

missione missioni[101];

int main(){
    assert(freopen("input.txt", "r", stdin)!=NULL);
	assert(freopen("output.txt", "w", stdout)!=NULL);
    int n;
    vector<int> dp;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> missioni[i].durata >> missioni[i].scadenza;
    }
    dp.resize(366, 0);
    for(int i=0; i<n; i++){
        for(int j=missioni[i].scadenza - missioni[i].durata; j>=0; j--){
            if(dp[j]+1 > dp[j+missioni[i].durata]){
                dp[j+missioni[i].durata] = dp[j]+1;
            }
        }
    }
    int ris = 0;
    for (auto x : dp){
        //cout << x << " ";
        if(x>ris) ris = x;
    }
    cout << ris;
}
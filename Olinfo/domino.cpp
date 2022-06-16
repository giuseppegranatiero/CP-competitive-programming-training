#include <bits/stdc++.h>
using namespace std;

pair<int,int> domino[10];
int n, ris = 0;
void swap(int j){
    domino[j] = make_pair(domino[j].second, domino[j].first);
}
void permute(int s, string save, int r){
    if(save.length() == n){
        ris = n;
        //cout << save << endl;
        return;
    }
    else{
        for(int i=0; i<n; ++i){
            if( save.find(to_string(i))==string::npos){
                if(domino[s].second == domino[i].first) permute(i, save+to_string(i), r+1);
                else if(domino[s].second == domino[i].second){
                    swap(i);
                    permute(i, save+to_string(i), r+1);
                }
                
            } 
        }
    }
    if(save.length() > ris) ris = save.length();
}

int main(){
    assert(freopen("input.txt", "r", stdin)!=NULL);
	assert(freopen("output.txt", "w", stdout)!=NULL);
    cin >> n;
    int a,b;
    for(int i=0; i<n; ++i){
        cin >> a >> b;
        domino[i] = make_pair(a,b);
    }
    for(int i=0; i<n; ++i){
        permute(i, ""+to_string(i), 1);
    }
    for(int i=0; i<n; ++i){
        swap(i);
        permute(i, ""+to_string(i), 1);
    }
    cout << ris;
}
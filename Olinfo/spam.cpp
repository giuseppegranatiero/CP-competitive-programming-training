#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //assert(freopen("inputSpan.txt","r",stdin)!=NULL);
    //assert(freopen("outputSpan.txt","w",stdout)!=NULL);
    assert(freopen("input.txt","r",stdin)!=NULL);
    assert(freopen("output.txt","w",stdout)!=NULL);
    int i,j,k,B,G,E,N;
    bool flagCattive,flagBuone;
    int paroleCattive=0,paroleBuone=0;
    int contatoreCattive=0,contatoreBuone=0;
    string appo;
    set<string> cattive;
    set<string> buone;
    cin>>B;
    for(i=0;i<B;i++){
        cin>>appo;
        cattive.insert(appo);
    }
    cin>>G;
    for(i=0;i<G;i++){
        cin>>appo;
        buone.insert(appo);
    }
    cin>>E;
    for(j=0;j<E;j++){
        cin>>N;
        paroleCattive=0;
        paroleBuone=0;
        for(k=0;k<N;k++){
            cin>>appo;
            flagCattive=false;
            flagBuone=false;
            if(cattive.find(appo)!=cattive.end()){
                paroleCattive++;
            }
            if(buone.find(appo)!=buone.end()){
                paroleBuone++;
            }
        }
        if(paroleBuone>0 && paroleCattive==0){
            contatoreBuone++;
        }
        if(paroleBuone==0 && paroleCattive>0){
            contatoreCattive++;
        }
    }
    cout<<contatoreCattive<<" "<<contatoreBuone<<endl;
}
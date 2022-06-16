#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;
struct Giocatore{
    long long int posizione;
    long long int amico;
    long long int P;
    long long int Q;
    long long int valore;      ///Questo campo mi servirà per calcolare effettivamente il valore di un giocatore
};
Giocatore giocatori[MAXN];

bool confronta(Giocatore a, Giocatore b){
    if(a.valore>b.valore){
        return true;
    }else{
        return false;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //assert(freopen("inputDream.txt","r",stdin)!=NULL);
    //assert(freopen("outputDream.txt","w",stdout)!=NULL);
    assert(freopen("input.txt","r",stdin)!=NULL);
    assert(freopen("output.txt","w",stdout)!=NULL);

    long long int N,K;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>giocatori[i].amico>>giocatori[i].P>>giocatori[i].Q;
        giocatori[i].posizione=i;
    }
    /*for(int i=0;i<N;i++){
        cout<<giocatori[i].amico<<" "<<giocatori[i].P<<" "<<giocatori[i].Q<<endl;
    }*/
    /**
        CALCOLO VALORE EFFETTIVO DEL GIOCATORE considerando il caso in cui giochi o non giochi con l'amico
    */
    for(int i=0;i<N;i++){
		int amicodiI=giocatori[i].amico;
		/**
            In questo primo controllo verifico se il PUNTEGGIO P del giocatore i-esimo, quando NON GIOCA con il suo migliore AMICO
            sia uguale al PUNTEGGIO P del suo migliore amico quando non gioca con LUI, in questo caso di parità verifico
            se il PUNTEGGIO Q del giocatore i-esimo quando gioca con il suo Migliore Amico è maggiore del PUNTEGGIO Q del suo
            migliore amico quando gioca con lui, in questo caso il suo valore e P, perchè sarà P??? perchè avendo un valore pari di P
            scelgo quello con un valore maggiore di Q ;-) ... semplice

        */

        if(giocatori[i].P==giocatori[amicodiI].P && giocatori[i].Q>giocatori[amicodiI].Q){
            giocatori[i].valore=giocatori[i].P;
            /**
                questo caso è banale ... scelgo quello con valore maggiore di P
            */
        }else if(giocatori[i].P>giocatori[amicodiI].P){
            giocatori[i].valore=giocatori[i].P;
            /**
                Questo ultimo caso si verifica quando il giocatore i-esimo ha un valore di P minore del suo amico, quindi in definitiva
                quale sarà il suo valore??
                allora se P è basso vuol dire che io inizialmente AVRO' SCELTO IL SUO MIGLIORE AMICO PER GIOCARE IN SQUADRA e quindi
                il suo valore, se lo vado a mettere in squadra sara:
                il suo punteggio Q (ossia il punteggio del giocatore quando gioca in squadra con il suo migliore amico) a questo punto
                devo sottrerre il punteggio P del suo migliore amico che sicuramente avrò messo in squadra e sostituirlo con il punteggio
                Q del suo migliore amico
                ...
                spero d'essere stato chiaro
            */
        }else{
            giocatori[i].valore=giocatori[i].Q - giocatori[amicodiI].P + giocatori[amicodiI].Q;
        }
    }
    sort(giocatori, giocatori+N,confronta);
    /*cout<<"Giocatori Ordinati"<<endl;
    for(int i=0;i<N;i++){
        cout<<giocatori[i].valore<<" "<<giocatori[i].amico<<" "<<giocatori[i].P<<" "<<giocatori[i].Q<<endl;
    }*/
    long long int S=0;
    for(long long int i=0;i<K;i++){
        //cout<<giocatori[i].valore<<endl;
        S=S+giocatori[i].valore;
    }
    cout<<S;
}
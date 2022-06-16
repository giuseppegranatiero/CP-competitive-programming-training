#include <bits/stdc++.h>
using namespace std;

map<long long int, long long int> libreria;

void aggiungi(long long int id){
    auto item = libreria.find(id);
    if(item != libreria.end()){
        libreria[id]++;
    }
    else{
        libreria.insert({id, 1});
    }
}

void togli(long long int id){
    libreria[id]--;
}

int conta(long long int id){
    return libreria[id];
}

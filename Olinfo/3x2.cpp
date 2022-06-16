#include <bits/stdc++.h>
#include <set>
using namespace std;

struct Confronta{
    bool operator()(int a,int b){
        if (a>b) return true;
        return false;
    }
};

int main(){
	assert(freopen("input.txt","r",stdin)!=NULL);
    assert(freopen("output.txt","w",stdout)!=NULL);
	multiset<int, Confronta> goods;
	int n, good, price=0, size;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> good;
		goods.insert(good);
	}
	multiset<int>::iterator it_goods=goods.begin();
	for(int i=1; i<=n; i++){
		// aggiungi tutti gli elementi che non abbiamo i multiplo di 3
		if (i%3!=0){
			price+=*it_goods;
		}
		it_goods++;
	}
	cout << price; 
} 
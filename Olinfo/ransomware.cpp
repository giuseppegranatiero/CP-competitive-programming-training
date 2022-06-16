#include <bits/stdc++.h>
using namespace std;

int main(){
	assert(freopen("input.txt","r",stdin)!=NULL);
    assert(freopen("output.txt","w",stdout)!=NULL);
	int n;
	cin >> n;
	string numeri[n];
	string code[10];
	for (int i=0; i<n; i++){
		cin >> numeri[i];
	}
	for (int i=0; i<10; i++){
		cin >> code[i];
	}
	string hash;
	for(int i=0; i<n; i++){
		string pass = "";
		while(numeri[i].length()>0){
		for(int chiave=0; chiave<10; chiave++){
			hash = code[chiave];
			if (numeri[i].substr(0, hash.length()) == hash){
				stringstream ss;
				ss << chiave;
				string add = ss.str();
				pass.append(add);
				numeri[i].erase(0, hash.length());
				}
    		}
		}
		cout << pass << endl;
	}
}
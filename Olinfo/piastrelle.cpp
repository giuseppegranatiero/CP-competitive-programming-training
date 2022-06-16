#include <iostream>
using namespace std;

void piastrelle(string ris, int k){
	//caso base 
	if (k==0){
	    cout << ris << endl;
	    return;
	}
	//caso generale
	if(k-1>=0) piastrelle(ris+"[O]", k-1);
	if(k-2>=0) piastrelle(ris+"[OOOO]", k-2);
}

int main(){
    int n;
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	cin >> n;
	piastrelle("", n);
}
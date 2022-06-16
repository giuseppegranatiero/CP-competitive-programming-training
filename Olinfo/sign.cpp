#include <iostream>
#include <cassert>
using namespace std;

int main(){
	assert(freopen("input.txt", "r", stdin)!=NULL);
	assert(freopen("output.txt", "w", stdout)!=NULL);
	int long long n, A, B;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> A >> B;
		if (A>0 && B>0) cout << "+"<< endl;
  		else if (A<=0 && B >=0) cout << "0"<< endl;
  		else if (A==B && A<0) cout << "-"<< endl;
  		else if (A==B && A>0) cout << "+"<< endl;
  		else if (A<0 && B<0){
  			if ((A-B+1)%2==0) cout << "+"<< endl;
  			else cout << "-"<< endl;}
	}
	return 0;
}
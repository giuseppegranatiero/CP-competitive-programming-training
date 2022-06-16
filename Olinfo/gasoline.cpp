#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	int price[n];
	int fuel[n];
	for (int i=0; i<n; i++){
		cin >> price[i];
	}
	for (int i=0; i<n; i++){
		cin >> fuel[i];
	}
	int bestPrice = 1000;
	long long int totalPrice=0;
	for (int i = 0; i < n; i++)
	{
	    // Update bestStation if we found a better station
	    if (bestPrice > price[i]) {
	        bestPrice = price[i];
	    }
	
	    // Buy gasoline and add computed price to totalPrice.
	    totalPrice += fuel[i] * bestPrice;
	}	
	cout << totalPrice;
}
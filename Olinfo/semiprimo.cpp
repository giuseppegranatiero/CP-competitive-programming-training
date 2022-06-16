#include <bits/stdc++.h> 
using namespace std; 
  
bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 
  
// Driver Program to test above function 
int main() 
{ 
	assert(freopen("input.txt","r",stdin)!=NULL);
    assert(freopen("output.txt","w",stdout)!=NULL);
    int n, p1=0, p2=0;
	cin >> n; 
	for (int i=3; i<n; i+=2){
		if (n%i==0){
			if (isPrime(i) && isPrime(n/i)){
				p1 = i;
				p2 = n/i;
				break;
			}
		}
	}
	cout << p1 << " " << p2;
}
#include <bits/stdc++.h>
using namespace std;

int exp(long long x, unsigned int y, int p)
{
    int res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
 

void decifra(int N, int d, int L, int messaggio[], char plaintext[]){
    /*for(int i=0; i<L; ++i){
        int base = (int)pow(messaggio[i]%N,d);
        int c = base%N;
        plaintext[i] = (char)c;
        cout << plaintext[i];
    }*/

    for(int i=0; i<L; i++){
        plaintext[i] = (char)exp(messaggio[i], d, N);
        cout << plaintext[i];
    }
}
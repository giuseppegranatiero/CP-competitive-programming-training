#include<iostream>
#include<fstream>
using namespace std;
 
#define NMAX 100000
 
int pallini[NMAX];
 
bool controllo(int lung, int p)
{
	for(int i=0; i < lung; i++)
		if(pallini[i] != pallini[p+i])
			return false;
	return true;
}
 
 
int main()
{
	ifstream fin ( "input.txt");
	ofstream fout("output.txt");
 
    int N;
	fin >> N;
	for(int i=0; i < N; i++)
		fin >> pallini[i];
 
    int lungMax=N/2;
    int lunghe =1;
    int volte;
    int prossima;
    while(lunghe <= lungMax)
    {
    	if(N%lunghe == 0)
    	{
    		volte   =N/lunghe;
    		prossima=1;
    		while(prossima < volte && controllo(lunghe, prossima*lunghe))
    			prossima++;
		}
		if(prossima >= volte) break;
		lunghe++;
	}
	
	if(lunghe > lungMax)
		fout << "2";
	else	
	    for(int i=0; i < lunghe; i++)
	    	fout << pallini[i] << ' ';
		
	return 0;
}
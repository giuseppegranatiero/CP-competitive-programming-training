#include <iostream>
#include <fstream>

using namespace std;

int G, P, T;

int main(){
	int c=1;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in>>G>>P;
	while(G>c+(P-1)){
		G-=c;
		T+=c;
		G-=(P-1);
		c++;
	}
	if (c>G) T+=G;
	else T+=c;
	out << T;
}
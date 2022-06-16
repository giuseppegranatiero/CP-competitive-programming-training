#include <iostream>
#include <fstream>
using namespace std;

int main (){
	ifstream fin ("input.txt");
	ofstream fout("output.txt");
	long long int n, somma, elemento;
	fin >> n;
	somma = 0;
	int y=0;
	for (int x=0; x<n; x++){
		fin >> elemento;
		if (elemento > y){
		somma+=elemento;
		y = elemento;}
	}
	fout << somma;
	return 0;
}

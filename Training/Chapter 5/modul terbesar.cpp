#include <iostream>

using namespace std;

int main(){
	int size;
	cin >> size;
	
	int bilangan[1001];
	
	int terbesar = 0;
	for(int x=0;x<size;x++){
		cin >> bilangan[x];
		if(bilangan[x] > terbesar) terbesar = bilangan[x];
	}
	
	for(int x=0;x<size;x++){
		
	}
	return 0;
}

#include <iostream>

using namespace std;

int main(){
	int bil;
	
	cin >> bil;
	
	int faktor[bil];
	
	for(int x=1;x<=bil;x++){
		faktor[x] = 0;
	}
	
	int highest = -1;
	int temp = bil;
	while(temp > 1){
		for(int x=2;x<=temp;x++){
			if(temp % x == 0){
				faktor[x]++;
				temp /= x;
				if(x > highest) highest = x;
				break;		
			}
		}
	}
	
	bool first = true;
	for(int x=2;x<=highest;x++){
		if(faktor[x] > 0){
			if(!first) cout << " x ";
			first = false;
			int pangkat = faktor[x];
			cout << x;
			if(pangkat > 1) cout << "^" << pangkat;
		}
	}
	cout << "\n";
}

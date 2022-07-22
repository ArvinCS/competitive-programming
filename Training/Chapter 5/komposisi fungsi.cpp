#include <iostream>
#include <cmath>

using namespace std;

int compFunc(int a, int b, int x){
	return abs(a*x + b);
}

int main(){
	int a,b,k,x;
	
	cin >> a;
	cin >> b;
	cin >> k;
	cin >> x;
	
	int hasil = x;
	for(int x=0;x<k;x++){
		hasil = compFunc(a,b,hasil);
	}	
	
	cout << hasil << "\n";
	return 0;
}

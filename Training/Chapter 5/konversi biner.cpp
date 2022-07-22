#include <iostream>

using namespace std;

string conversi(int n){
	if(n == 1){
		return "1";
	} else if(n % 2 == 0){
		return conversi(n/2) + "0";
	} else {
		return conversi(n/2) + "1";
	}
}

int main(){
	int n;
	cin >> n;
	
	cout << conversi(n) << "\n"; 
	return 0;
}

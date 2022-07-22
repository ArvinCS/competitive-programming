#include <iostream>

using namespace std;

int ganepFactorial(int n){
	int temp = n;
	if(n == 1){
		return n;
	} else if(n % 2 == 0){
		n /= 2;
	}
	return n * ganepFactorial(temp-1);
}

int main(){
	int a,b,k,x;
	cin >> a,b,k,x;
	
	cout << ganepFactorial(n) << "\n";
	return 0;
}

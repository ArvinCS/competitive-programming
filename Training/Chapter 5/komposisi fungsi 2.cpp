#include <iostream>
#include <cmath>

using namespace std;

int fungsiDengklek(int a, int b, int k, int x){
	if(k == 0) {
		return x;
	}
	return fungsiDengklek(a,b,k-1,abs(a*x + b));
}

int main(){
	int a,b,k,x;
	cin >> a;
	cin >> b;
	cin >> k;
	cin >> x;
	
	cout << fungsiDengklek(a,b,k,x) << "\n";
	return 0;
}

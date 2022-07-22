#include <iostream>
#include <cmath>

using namespace std;

void fp(int n){
	int origin = n;
	int primes[n+1];
	fill_n(primes, n+1, 0);
	while (n%2 == 0){
    	primes[2]++;
    	n = n/2;
	}
	
	if(n >= 3){
		for (int i = 3; i <= sqrt(origin); i = i+2){
			while (n%i == 0){
				primes[i]++;
				n = n/i;
			}
		}
	}
	
	if(n > 2) primes[n]++;
	
	bool newline = true;
	for(int x=2;x<=origin;x++){
		if(primes[x] > 0){
			if(newline) {
				newline = false;
			} else {
				cout << " x ";
			}
			if(primes[x] > 1){
				cout << x << "^" << primes[x];
			} else {
				cout << x;
			}
		}
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	fp(n);
    return 0;
}

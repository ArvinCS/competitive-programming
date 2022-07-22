#include <iostream>

using namespace std;

const int mxP = 10e5;
bool primes[mxP+1] = { 0 };
int cache[77777] = { 0 };

int getPrime(int k){
	if(cache[k] > 1) return cache[k];
	int n = 0;
	for(int x=2;x<=mxP;x++){
		if(!primes[x]){
			n++;
			cache[n] = x;
			if(n==k) return x;
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	primes[1] = true;
	int n = 0;

	for(int x=2;x*x<=mxP;x++){
		if(!primes[x]){
			n++;
			cache[n] = x;
			for(int i=x*2;i<=mxP;i+=x){
				if(!primes[i]){
					primes[i] = true;
				}
			}
		}
	}

	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		cout << getPrime(k) << "\n";
	}
    return 0;
}



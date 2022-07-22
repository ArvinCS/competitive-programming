#include <iostream>

using namespace std;

int gcd(int a, int b) 
{ 
    if (b == 0) return a; 
    return gcd(b, a % b); 
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int primes[11] = {2,3,5,7,11,13,17,19,23,29,31}, t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int data[n], count[11] = { 0 };
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		int maxPrime = 0;
		for(int x=0;x<n;x++){
			int lastPrime = 0;
			for(int p=0;p<11;p++){
				if(data[x] % primes[p] == 0){
					lastPrime = p;
					if(count[lastPrime] == 0){
						break;
					}
				}
			}
			count[lastPrime]++;
			data[x] = lastPrime+1;
			maxPrime = max(maxPrime, lastPrime);
		}
		
		cout << maxPrime + 1 << "\n";
		for(int x=0;x<n;x++){
			cout << data[x] << " ";	
		}
		cout << "\n";
	}
    return 0;
}

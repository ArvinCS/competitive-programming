#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

const int maxN = 2 * 1e5;

int cntPrimes[maxN];
bool primes[maxN];
	
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(cntPrimes, cntPrimes+maxN, 0);
	
	primes[1] = 1;
	for(ull x=2;x*x<=maxN;x++){
		if(cntPrimes[x] > 0) continue;
		for(ull y=2*x;y<=maxN;y+=x){
			cntPrimes[y]++;
		}
	}
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		if(n <= 30){
			cout << "NO\n";
		} else if(n == 36 || n == 40 || n == 44){
			cout << "YES\n";
			cout << "6 10 15 " << n-6-10-15 << "\n";
		} else {
			cout << "YES\n";
			cout << "6 10 14 " << n-6-10-14 << "\n";
		}
	}
	
    return 0;
}


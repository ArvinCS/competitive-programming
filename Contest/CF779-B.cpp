#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;
const int maxN = 1e3 + 5;

ll fac[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fac[0] = fac[1] = 1;
	for(int x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % mod;
	}
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		if(n % 2 == 0){
			ll ans = (fac[n/2] * fac[n/2]) % mod;
			
			cout << ans << "\n";
		} else {
			cout << "0\n";
		}
	}
	
    return 0;
}


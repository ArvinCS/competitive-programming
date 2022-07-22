#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

ll power(ll x, ll y){
	ll ans = 1;
	x %= mod;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	
	return ans;
}

ll inv(ll n){
	return power(n, mod-2);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll fac[1001];
	fac[0] = 1;
	
	for(ll x=1;x<=1000;x++){
		fac[x] = x * fac[x-1];
		fac[x] %= mod;	
	}
	
	us t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		int weight[n];
		for(int x=0;x<n;x++){
			cin >> weight[x];
		}
		
		sort(weight, weight+n);
		
		int left = n-k, right = n-k, cnt = 1;
		while(left > 0 && weight[left-1] == weight[n-k]){
			left--;
		}
		while(right < n-1 && weight[right+1] == weight[n-k]){
			right++;
			cnt++;
		}
		cout << (fac[right-left+1] * inv(fac[cnt]) % mod * inv(fac[right-left+1-cnt]) % mod) % mod << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar


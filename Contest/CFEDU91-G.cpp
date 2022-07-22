#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;

ll powmod(ll x, ll y){
	ll ans = 1;
	
	x %= mod;
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll c[n];
	for(int x=0;x<n;x++){
		cin >> c[x];
	}
	
	sort(c, c+n, greater<ll>());
	
	for(int x=1;x<n;x++){
		c[x] += c[x-1];
	}
	
	ll ans[n+1];
	fill(ans, ans+n+1, 0);
	for(int x=1;x<=n;x++){
		for(int y=1;y*x<n;y++){
			int l = x+(y-1)*x, r = min(n-1, x+y*x-1);
			if(l > r) break;
			
			ans[x] += (c[r] - (l > 0 ? c[l-1] : 0)) * y % mod;
			if(ans[x] >= mod) ans[x] -= mod;
		}
	}
	
	ll inv = powmod(n, mod-2);
	
	for(int x=1;x<=n;x++){
		if(x > 1) cout << " ";
		cout << ans[x] * inv % mod;
	}
	cout << "\n";
    return 0;
}


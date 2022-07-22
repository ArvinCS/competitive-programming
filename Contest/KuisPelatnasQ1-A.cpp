#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int maxN = 1e5 + 5;

ll fac[maxN], iv[maxN];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

ll combin(ll x, ll y){
	if(x < y) return 0;
	return fac[x] * iv[x-y] % mod * iv[y] % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(1, mod-2);
	
	for(int x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % mod;
		iv[x] = powmod(fac[x], mod-2);
	}	
	
	int n;
	cin >> n;
	
	int p[n], t[n];
	fill(t, t+n, -1);
	
	for(int x=0;x<n;x++){
		cin >> p[x];
		if(p[x] >= 0) p[x]--;
		t[p[x]] = x;
	}
	
	vector<int> v;
	for(int x=0;x<n;x++){
		if(t[x] != -1){
			v.push_back(x);
		}
	}		
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		if(!v.empty() && v[0] == 0 && t[v[0]] != x) continue;
		if(p[x] > 0) continue;
		
		ll cnt = 1;
		
		int pos = 1, mn = x, mx = x;
		for(int y=(!v.empty() && v[0] == 0 ? 1 : 0);y<v.size();y++){
			if(x < t[v[y]] && mx >= t[v[y]]){
				cnt = 0;
				break;
			}
			if(x >= t[v[y]] && mn <= t[v[y]]){
				cnt = 0;
				break;
			}
			
			cnt *= combin(v[y]-pos, (x < t[v[y]] ? t[v[y]]-mx-1 : mn-t[v[y]]-1));
			cnt %= mod;
			
			int val1 = (x < t[v[y]] ? v[y]-pos-(t[v[y]]-mx-1) : mn-t[v[y]]);
			int val2 = (x < t[v[y]] ? t[v[y]]-mx : v[y]-pos-(mn-t[v[y]]-1));
			
			mn -= val1;
			mx += val2;
			
			pos = v[y]+1;
		}
		
		if(mn < 0 || mx > n){
			cnt = 0;
		} else {
			cnt *= combin(n-pos, mn);
			cnt %= mod;
		}
		
		ans += cnt;
		ans %= mod;
	}
	
	cout << ans << "\n";
	return 0;
}

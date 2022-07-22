#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;
const int maxN = 3e5 + 5;

ll fac[maxN], iv[maxN];

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

ll comb(int n, int r){
	if(n < r) return 0;
	return fac[n] * iv[n-r] % mod * iv[r] % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(fac[1], mod-2);
	for(int x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % mod;
		iv[x] = powmod(fac[x], mod-2);
	}
	
	int n, m;
	cin >> n >> m;
	
	int l[n], r[n];
	for(int x=0;x<n;x++){
		cin >> l[x] >> r[x];
		l[x]--; r[x]--;
	}
	
	pair<int, int> p[m];
	for(int x=0;x<m;x++){
		cin >> p[x].first >> p[x].second;
		p[x].first--; p[x].second--;
	}
	
	int prefix[n+1];
	fill(prefix, prefix+n+1, 0);
	
	for(int x=0;x<n;x++){
		prefix[l[x]]++;
		prefix[r[x]+1]--;
	}
	
	for(int x=1;x<=n;x++){
		prefix[x] += prefix[x-1];
	}
	
	int mx = min(50, n);
	ll table[mx+1][n];
	fill(table[0], table[mx+1], 0);
	
	for(int x=0;x<=mx;x++){
		for(int y=0;y<n;y++){
			if(y > 0) table[x][y] += table[x][y-1];
			table[x][y] %= mod;
			
			table[x][y] += (prefix[y] >= x && y+1 >= x ? comb(prefix[y]-x, y+1-x) : 0);
			table[x][y] %= mod;
		}
	}
	
	ll ans = table[0][n-1];
	for(int state=1;state<(1 << m);state++){
		vector<int> v;
		for(int y=0;y<m;y++){
			if(state&(1 << y)){
				v.push_back(p[y].first);
				v.push_back(p[y].second);
			}
		}
		
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		
		int left = 0, right = n-1;
		int cur = 0;
		for(int y=0;y<v.size();y++){
			left = max(left, l[v[y]]);
			right = min(right, r[v[y]]);
			
			for(int z=y+1;z<v.size();z++){
				for(int x=0;x<m;x++){
					if(p[x].first == v[y] && p[x].second == v[z]){
						cur |= (1 << x);
						break;
					}
				}
			}
		}
		
		if(left > right) continue;
		
		int cnt = v.size();
		if(__builtin_popcount(state)&1) ans -= (table[cnt][right] - (left > 0 ? table[cnt][left-1] : 0) + mod) % mod;
		else ans += (table[cnt][right] - (left > 0 ? table[cnt][left-1] : 0) + mod) % mod;
		
		if(ans < 0) ans += mod;
		ans %= mod;
	}
	
	cout << ans << "\n";
    return 0;
}


#include <bits/stdc++.h>
#include <chrono>
#include <random>

using namespace std;

#define ll long long

const int maxN = 1e6 + 5;
const ll mod = 1e9 + 7;

ll key[2*maxN];

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
	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	for(int x=0;x<2*maxN;x++){
		key[x] = (997ll*x) % mod;
	}
	
	int n;
	cin >> n;
	
	vector<ll> v;
	ll a[2*n], b[2*n];
	ll hashA[2*n], hashB[2*n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		a[n+x] = a[x];
		
		v.push_back(a[x]);
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
		b[n+x] = b[x];
		
		v.push_back(b[x]);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	shuffle(key, key+2*maxN, rng);
	
	for(int x=0;x<2*n;x++){
		if(x > 0){
			hashA[x] = hashA[x-1];
			hashB[x] = hashB[x-1];
		} else {
			hashA[x] = hashB[x] = 0;
		}
		
		hashA[x] += key[(lower_bound(v.begin(), v.end(), a[x]) - v.begin())];
		hashA[x] %= mod;
		hashB[x] += key[(lower_bound(v.begin(), v.end(), b[x]) - v.begin())];
		hashB[x] %= mod;
	}
	
//	cout << hashA[2*n-1] << " " << hashB[2*n-1] << "\n";
	
	
	set<ll> st;
	
	ll ans = 0;
	int cnt[2*n];
	fill(cnt, cnt+2*n, 0);
	
	for(int x=0;x<2*n;x++){
		if(x > 0) cnt[x] = cnt[x-1];
		else cnt[x] = 0;
		
		ll valLa = hashA[x];
		ll valLb = hashB[x];
		
		ll valRa = (hashA[2*n-1] - hashA[x] + mod) % mod;
		ll valRb = (hashB[2*n-1] - hashB[x] + mod) % mod;
		
		if(valLa == valLb && valRa == valRb){
			cout << x << "\n";
			cnt[x]++;
		}
	}
	
	for(int x=0;x<n;x++){
		int val = cnt[x+n-1] - (x > 0 ? cnt[x-1] : 0);
		
		ans += (powmod(2, val) - val - 1 + 2*mod) % mod;
		ans %= mod;
	}
	
	cout << ans << "\n";
    return 0;
}


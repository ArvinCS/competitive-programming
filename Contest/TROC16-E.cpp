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

const int maxN = 1e5 + 5;

int prime[maxN];
vector<pair<ll, ll>> v[maxN];

ll modpow(ll x, ll y){
	ll ans = 1;
	x %= mod;
	
	while(y>0){
		if(y&1) ans = (ans*x) % mod;
		
		y>>=1;
		x=(x*x)%mod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	for(int x=0;x<maxN;x++) prime[x] = x;
	for(int x=2;x*x<maxN;x++){
		if(prime[x] == x){
			for(int y=x+x;y<maxN;y+=x){
				if(prime[y] == y) prime[y] = x;
			}
		}
	}
	
	int n;
	cin >> n;
	
	ll data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	for(int x=0;x<n;x++){
		ll cur = data[x];
		while(cur > 1){
			ll div = prime[cur], cnt = 0;
			while(cur % div == 0){
				cnt++;
				cur /= div;
			}
			
			v[div].push_back({cnt, -x});
		}
	}
	
	ll ans = 1;
	for(ll x=2;x<maxN;x++){
		if(v[x].size() == 0) continue;
		
		sort(v[x].rbegin(), v[x].rend());
		
		set<int> st;
		st.insert(-1);
		st.insert(n);
		
		for(int y=0;y<v[x].size();y++){
			int idx = -v[x][y].second;
			auto it1 = st.lower_bound(idx);
			auto it2 = st.lower_bound(idx);
			it1--;
			
			ll l = (*it1 + 1), r = (*it2 - 1);
			ans *= modpow(modpow(x, v[x][y].first), (idx-l+1) * (r-idx+1));
			ans %= mod;
			st.insert(idx);
		}
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar


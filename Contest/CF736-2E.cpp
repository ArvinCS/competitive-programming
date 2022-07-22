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

const int maxN = 3e6 + 5;

ll fac[maxN], iv[maxN];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y>0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x*x) % mod;
	}
	return ans;
}

ll combin(ll x, ll y){
	return fac[x] * iv[x-y] % mod * iv[y] % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(1, mod-2);
	
	for(ll x=2;x<maxN;x++){
		fac[x] = (x*fac[x-1]) % mod;
		iv[x] = powmod(fac[x], mod-2);
	}
	
	int n, m;
	cin >> n >> m;
	
	for(int x=1;x<=n;x++){
		for(int y=1;y<=n;y++){
			cout << x << " " << 3*y << " -> " << combin(3*y, x) << "\n";		
		}
	}
	
	vector<pair<int, int>> v;
	for(int x=0;x<m;x++){
		int val;
		cin >> val;
		
		v.push_back({val, x});
	}

	int ans[m];
	fill(ans, ans+m, -1);
	
	sort(v.begin(), v.end());
	
//	int pos = 1, cur = 1;
//	ll sum = n*(2*3 + (n-1)*3)/2;
//	ll cnt = 1;
//	for(int x=0;x<m;x++){
//		while(3*pos < v[x].first){
//			sum -= combin(3*pos, cur);
//			pos++;
//		}
//		
//		while(cur < v[x].first){
//			ll tmp = 
//			sum = (sum - n*+ mod) % mod;
//			
//			
//			cur++;
//			ans[v[x].second] = sum;	
//		}
//	}
//	
//	for(int x=0;x<m;x++){
//		cout << ans[x] << "\n";
//	}
    return 0;
}


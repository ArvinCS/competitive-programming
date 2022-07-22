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

const int maxN = 25, maxM = 5e4 + 5;

ll fac[maxN];
vector<pair<int, int>> v[maxM];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y>0){
		if(y&1) ans = (ans*x) % smod;
		
		y >>= 1;
		x = (x*x) % smod;
	}
	return ans;
}

ll combin(ll x, ll y){
	return fac[x] * powmod(fac[x-y], smod-2) % smod * powmod(fac[y], smod-2) % smod;
}

ll permut(ll x, ll y){
	return fac[x] * powmod(fac[x-y], smod-2) % smod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	fac[0] = fac[1] = 1;
	for(ll x=2;x<maxN;x++){
		fac[x] = (x*fac[x-1]) % smod;
	}
	
	int n, m;
	cin >> n >> m;
	
	int d[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> d[x][y];
			v[y].push_back({d[x][y], x});
		}
	}
	
	for(int x=0;x<m;x++){ // points
		sort(v[x].begin(), v[x].end());
	}
	
	ll ans = 0;
	for(int x=0;x<m;x++){ // cities
		ll left = 0, cnt = 1;
		
		for(int y=0;y<v[x].size();y++){ // move between cities
			left += v[x][y].first - (y > 0 ? v[x][y-1].first : 1);
			
//			cout << left << "\n";
			cnt *= left--; // available positions to take
			cnt %= smod;	
		}
		
		ans += (fac[n] - cnt + smod) % smod;
		ans %= smod;
//		cout << x << ": " << ans << " " << cnt << "\n";
	}
	
	cout << (ans * powmod(fac[n], smod-2)) % smod << "\n";
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int maxN = 2e4;

ll fac[maxN], iv[maxN];

void chadd(ll &a, ll b){
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

ll powmod(ll x, ll y){
	ll ans = 1;
	
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
	
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = 1;
	
	for(int x=2;x<maxN;x++){
		fac[x] = (fac[x-1] * x) % mod;
		iv[x] = powmod(fac[x], mod-2);
	}
	
	int n, m;
	cin >> n >> m;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	sort(a, a+n);
	
	// DP CC, dp[used_spaces][cur_idx][num_components]
	
	ll dp[m+1][n+1][n+1];
	fill(*dp[0], *dp[m+1], 0);
	dp[1][0][1] = 1;
	
	for(int s=0;s<=m;s++){
		for(int x=1;x<n;x++){
			ll sum = 0;
			for(int c=0;c<=n;c++){
				if(s-2*a[x]+1 >= 0 && c+1 <= n){ // connect two of existing adjacent ccs
					chadd(dp[s][x][c], c*(dp[s-2*a[x]+1][x-1][c+1]) % mod);
				}
				if(s-a[x] >= 0){ // use and keep one of existing ccs
					chadd(dp[s][x][c], 2*c*(dp[s-a[x]][x-1][c]) % mod);
				}
				if(s-1 >= 0 && c-1 >= 0){ // create new cc
					chadd(dp[s][x][c], c*dp[s-1][x-1][c-1] % mod);
				}
			}
		}
	}
	
	ll ans = 0;
	for(int s=0;s<=m;s++){
		int extra = (m-s);
		chadd(ans, fac[n+extra] * iv[extra] % mod * iv[n] % mod * dp[s][n-1][1] % mod);
	}
	
	cout << ans << "\n";
    return 0;
}


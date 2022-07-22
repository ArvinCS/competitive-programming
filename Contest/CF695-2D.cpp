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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, k, q;
	cin >> n >> k >> q;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	ll table[k+1][n];
	fill(table[0], table[k+1], 0);
	
	for(int x=0;x<n;x++){
		table[0][x] = 1;
	}
	for(int x=1;x<=k;x++){
		for(int y=0;y<n;y++){
			if(y-1 >= 0) table[x][y] += table[x-1][y-1];
			table[x][y] %= mod;
			if(y+1 < n) table[x][y] += table[x-1][y+1];
			table[x][y] %= mod;
		}
	}
	
	ll ways[n];
	fill(ways, ways+n, 0);
	
	for(int x=0;x<=k;x++){
		for(int y=0;y<n;y++){
			ways[y] += table[x][y] * table[k-x][y] % mod;
			ways[y] %= mod;
		}
	}
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		ans += ways[x] * a[x] % mod;
		ans %= mod;
	}
	
	for(int i=0;i<q;i++){
		int idx;
		ll val;
		cin >> idx >> val;
		
		idx--;
		ans -= ways[idx] * a[idx] % mod;
		ans = (ans + mod) % mod;
		
		a[idx] = val;
		
		ans += ways[idx] * a[idx] % mod;
		ans %= mod;
		
		cout << ans << "\n";
	}
    return 0;
}


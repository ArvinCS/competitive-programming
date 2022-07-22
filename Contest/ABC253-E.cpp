#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;

void chadd(ll &a, ll b){
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	ll table[n][m+1];	
	fill(table[0], table[n], 0);
	
	for(int y=1;y<=m;y++) table[0][y] = 1;
	for(int x=0;x+1<n;x++){
		ll pref = 0, suff = 0;
		for(int y=m;y>=1+k;y--) chadd(suff, table[x][y]);
		for(int y=1;y<=m;y++){
			if(k > 0 && y-k >= 1) chadd(pref, table[x][y-k]);
			
			chadd(table[x+1][y], pref);
			chadd(table[x+1][y], suff);
			
			if(k > 0 && y+k <= m) chadd(suff, -table[x][y+k]);
		}
	}
	
	ll ans = 0;
	for(int y=1;y<=m;y++) chadd(ans, table[n-1][y]);
	
	cout << ans << "\n";
    return 0;
}


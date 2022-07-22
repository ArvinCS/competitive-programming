#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m, q;
		ll k;
		cin >> n >> m >> k >> q;
		
		pair<int, int> p[q];
		for(int x=0;x<q;x++){
			cin >> p[x].first >> p[x].second;
			
			p[x].first--; p[x].second--;
		}
		
		int row = 0, col = 0;
		
		bool r[n+1], c[m+1];
		fill(r, r+n+1, false);
		fill(c, c+m+1, false);
		
		ll ans = 1;
		for(int x=q-1;x>=0;x--){
			if(!r[p[x].first] && !c[p[x].second] && row < m && col < n){
				ans *= k;
				ans %= mod;
				r[p[x].first] = c[p[x].second] = true;
				row++;
				col++;
			} else if(!r[p[x].first] && row < m){
				ans *= k;
				ans %= mod;
				r[p[x].first] = true;
				col++;
			} else if(!c[p[x].second] && col < n){
				ans *= k;
				ans %= mod;
				c[p[x].second] = true;
				row++;
			}
		}
		
		cout << ans % mod << "\n";
	}	
	
    return 0;
}


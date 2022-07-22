#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e6 + 5;

ll table[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll m;
	cin >> n >> m;
	
	fill(table, table+n+1, 0);
	
	ll ans = 1;
	for(int x=n;x>=2;x--){
		ll cnt = m;
		int y = 2;
		for(ll cur = x*1ll*x;cur<=n&&y<=30;cur*=x, y++){
			cnt -= min(m/y, table[cur]);
		}
		for(;y<=900;y++){
			cnt -= min(m/y, table[])
		}
		
		table[x] = cnt;
		ans += cnt;
		cout << x << " -> " << cnt << "\n";
	}
	
	cout << ans << "\n";
    return 0;
}


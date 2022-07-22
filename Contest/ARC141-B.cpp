#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n, m;
	cin >> n >> m;
	
	if(n > 100){
		cout << "0\n";
		return 0;
	}
	
	ll table[n][60];
	fill(table[0], table[n], 0);
	
	for(int x=0;x<60;x++){
		ll cnt = max(0ll, min((1ll << (x+1))-1, m)-(1ll << x)+1) % mod;
		table[0][x] += cnt;
		table[0][x] %= mod;
	}
	
	for(int x=1;x<n;x++){
		ll sum = 0;
		for(int y=0;y<60;y++){
			ll cnt = max(0ll, min((1ll << (y+1))-1, m)-(1ll << y)+1) % mod;
			table[x][y] += sum*cnt % mod;
			table[x][y] %= mod;
			
			sum += table[x-1][y];
			sum %= mod;
		}
	}
	
	ll ans = 0;
	for(int x=0;x<60;x++){
		ans += table[n-1][x];
		ans %= mod;
	}
	
	cout << ans << "\n";
    return 0;
}


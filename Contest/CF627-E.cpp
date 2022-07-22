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
	
	int n, h, l, r;
	cin >> n >> h >> l >> r;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	ll table[n+1][n+1];
	fill(table[0], table[n+1], -inf_ll);
	
	ll cnt = 0;
	table[0][0] = 0;
	
	for(int x=0;x<n;x++){
		cnt += data[x];
		for(int y=0;y<=x;y++){
			ll tmp = (cnt-y)%h;
			table[x+1][y] = max(table[x+1][y], table[x][y] + (l <= tmp && tmp <= r));
			tmp = (cnt-y-1)%h;
			table[x+1][y+1] = max(table[x+1][y+1], table[x][y] + (l <= tmp && tmp <= r));
		}
	}
	
	ll ans = 0;
	for(int x=0;x<=n;x++){
		ans = max(ans, table[n][x]);
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar


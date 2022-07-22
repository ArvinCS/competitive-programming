#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007

const ll smod = 998244353;
const int maxN = 5 * 1e3 + 10;

char grid[maxN][maxN];
ll table[maxN][maxN];

ll mul(ll a, ll b){
	ll res = 0;
	a %= smod;
	b %= smod;
	
	while(b > 0){
		if(b&1) res = (res + a) % smod;
		
		a = (a*2ll) % smod;
		b /= 2;
	}
	
	return res % smod;
}

ll pw(ll a, ll b){
	if(b == 0) return 1;
	ll tmp = pw(a, b/2) % smod;
	if(b&1) return mul(mul(tmp, tmp), a);
	return mul(tmp, tmp);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll h, w, k;
	cin >> h >> w >> k;
	
	fill(grid[0], grid[h+1], '.');
	
	for(ll x=0;x<k;x++){
		ll a, b;
		char c;
		cin >> a >> b >> c;
		
		grid[a-1][b-1] = c;
	}
	
	for(ll x=0;x<=h;x++){
		for(ll y=0;y<=w;y++) table[x][y] = 0;
	}
	
	table[0][0] = pw(3, h*w-k) % smod;
	
	for(ll x=0;x<h;x++){
		for(ll y=0;y<w;y++){
			if(grid[x][y] == '.'){
				ll tmp = table[x][y] * 2 / 3;
				table[x+1][y] += tmp % smod;
				table[x][y+1] += tmp % smod; // x
				table[x+1][y] %= smod;
				table[x][y+1] %= smod;
			} else if(grid[x][y] == 'X'){
				table[x+1][y] += table[x][y] % smod;
				table[x][y+1] += table[x][y] % smod;
				table[x+1][y] %= smod;
				table[x][y+1] %= smod;
			} else if(grid[x][y] == 'R'){
				table[x][y+1] += table[x][y] % smod;
				table[x][y+1] %= smod;
			} else if(grid[x][y] == 'D'){
				table[x+1][y] += table[x][y] % smod;
				table[x+1][y] %= smod;
			}
		}
	}
	
	cout << table[h-1][w-1] % smod << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar


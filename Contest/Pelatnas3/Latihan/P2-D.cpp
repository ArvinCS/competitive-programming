#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;
const int maxN = 2505;
const ll key = 31;
const ll key2 = 37;

ll pw[maxN], pw2[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	pw[0] = pw2[0] = 1;
	for(int x=1;x<maxN;x++){
		pw[x] = (key * pw[x-1]) % mod;
		pw2[x] = (key2 * pw2[x-1]) % mod;
	}
	
	ll a, b, c;
	cin >> a >> b >> c;
	
	string s;
	cin >> s;
	
	int n = s.length();
	
	ll h[n+1][2];
	h[0][0] = h[0][1] = 0;
	for(int x=0;x<n;x++){
		h[x+1][0] = ((s[x] - 'a' + 1) + h[x][0] * key) % mod;
		h[x+1][1] = ((s[x] - 'a' + 1) + h[x][1] * key2) % mod;
	}
	
	auto getHash = [&](int l, int r, int id) -> ll {
		assert(l <= r);
		return (h[r+1][id] - (h[l][id] * (id ? pw2[r-l+1] : pw[r-l+1]) % mod) + mod) % mod;
	};
	
	ll table[n+1][n+1];
	ll ans = 1e18;
	for(int t=0;t<n;t++){
		fill(table[0], table[n+1], 1e18);
		
		table[t][0] = t*a + a;
		table[t][1] = t*a + a+b+c;
		for(int x=t+1;x<n;x++){
			for(int y=0;y<=n;y++){
				if(table[x-1][y] == 1e18) continue;
				
				table[x][y] = min(table[x][y], table[x-1][y]+a); // type
			}
			
			for(int y=t;y<x;y++){
				int z = (x-y);
				if(t+z-1 >= n || table[y][z] == 1e18) continue;
				
				bool same = true;
				for(int i=0;i<x-y;i++){
					if(s[t+i] != s[y+1+i]) same = false;
				}
				
				// paste
//					cout << "[" << t << "," << t+z-1 << "] [" << y+1 << "," << x << "]" << " = " << same << "\n";
				if(same){
					table[x][z] = min(table[x][z], table[y][z]+c);
				}
			}
			
			for(int y=0;y<=n;y++){
				if(table[x][y] == 1e18) continue;
				
				table[x][x-t+1] = min(table[x][x-t+1], table[x][y]+b+c); // select all and no cut
			}
		}
		
		for(int x=0;x<=n;x++){
			if(table[n-1][x] == 1e18) continue;
////			cout << t << " " << x << " -> " << table[n-1][x]+t*a << "\n";
			ans = min(ans, table[n-1][x]);
		}
	}
	
	assert(ans < 1e18);
	assert(ans > 0);
	
	cerr << n << "\n";
	cout << ans << "\n";
    return 0;
}


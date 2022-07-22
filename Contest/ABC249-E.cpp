#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll maxN = 3005;

ll mod;
ll table[maxN][maxN];

void chadd(ll &a, ll b){
	a += b;
	a %= mod;
	if(a < 0) a += mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n >> mod;
	
	fill(table[0], table[maxN], 0);
	
	ll ans = 0;
	table[0][0] = 1;
	table[0][1] = -1;
	for(int x=0;x<n;x++){
		ll cur = 0;
		for(int y=0;y<=n;y++){
			chadd(cur, table[x][y]);
			
			if(y == n){
				chadd(ans, cur);	
			}
			
			int pw = 1;
			for(int z=1;z<=4;z++){
				if(x+1+z > n) break;
				
				int length = min(pw*10-1, n-y)-pw+1;
				if(length < 0) break;
				
				if(y+length+1 <= n) chadd(table[x+1+z][y+length+1], -(cur * (x > 0 ? 25 : 26) % mod));
				if(y+1 <= n) chadd(table[x+1+z][y+1], (cur * (x > 0 ? 25 : 26) % mod));
				pw *= 10;
			}
		}
	}
	
	cout << ans % mod << "\n";
    return 0;
}


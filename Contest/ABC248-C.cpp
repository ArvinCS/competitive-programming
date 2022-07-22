#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	ll table[n+1][k+1];
	fill(table[0], table[n+1], 0);
	
	table[0][0] = 1;
	for(int x=0;x<n;x++){
		for(int y=0;y<=k;y++){
			for(int z=1;z<=m;z++){
				if(y+z <= k){
					table[x+1][y+z] += table[x][y]; 
					table[x+1][y+z] %= mod;
				}
			}
		}
	}
	
	ll ans = 0;
	for(int y=0;y<=k;y++){
		ans += table[n][y];
		ans %= mod;
	}
	
	cout << ans << "\n";
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	pair<int, int> p[n], q[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first;
		p[x].second = x;
	}
	for(int x=0;x<n;x++){
		cin >> q[x].first;
		q[x].second = x;
	}
	
	sort(p, p+n);
	
	int table[k+1][n+1][n+1];
	fill(*table[0], *table[k+1], 0);
	
	table[0][0][n] = 1;
	
	for(int x=0;x<n;x++){
		int idx = p[x].second;
		for(int y=0;y<=k;y++){
			for(int z=0;z<=n;z++){
				if(y+1 <= k && q[idx].first <= z){
					table[y+1][x+1][z] += table[y][x][z];
					table[y+1][x+1][z] %= mod;
				}
				
				table[y][x+1][min(z, q[idx].first)] += table[y][x][z];
				table[y][x+1][min(z, q[idx].first)] %= mod;
			}
		}
	}
	
	ll ans = 0;
	for(int z=0;z<=n;z++){
		ans += table[k][n][z];
		ans %= mod;
	}
	cout << ans << "\n";
    return 0;
}


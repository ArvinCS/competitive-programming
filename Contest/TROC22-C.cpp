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

const int maxN = 1e5 + 5;

int n, k, a[maxN], cost[15][15];
ll table[maxN][15];
ll suffix[maxN][15];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n >> k;
	
	string s;
	cin >> s;
	
	for(int x=1;x<=k;x++){
		for(int y=1;y<=k;y++){
			cin >> cost[x][y];
		}
	}
	
	for(int x=0;x<n;x++){
		a[x] = (s[x] - '0');
	}
	
	fill(table[0], table[maxN], -inf_ll);
	fill(suffix[0], suffix[maxN], -inf_ll);
	
	ll ans = 0;
	suffix[n-1][a[n-1]] = table[n-1][a[n-1]] = 0;
	for(int x=n-2;x>=0;x--){
		for(int y=1;y<=k;y++){
			table[x][y] = table[x+1][y]+cost[a[x]][a[x+1]];
			suffix[x][y] = suffix[x+1][y];
		}
		
		if(x+2 < n){
			for(int y=1;y<=k;y++){				
				ll val = table[x+2][y]+cost[a[x+1]][a[x+2]]+cost[a[x]][a[x+1]]-cost[a[x]][y];
				
				ans = max(ans, val);
				
				table[x][a[x]] = max(table[x][a[x]], val);
				suffix[x][a[x]] = max(suffix[x][a[x]], val);
			}
		}
		
		for(int y=1;y<=k;y++){
			table[x][a[x]] = max(table[x][a[x]], suffix[x+1][y]);
		}
	}
	
	cout << ans << "\n";
    return 0;
}


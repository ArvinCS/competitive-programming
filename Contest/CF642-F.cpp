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

int n, m;
ll a[105][105];

ll calc(ll val){
	ll table[n][m];
	fill(table[0], table[n], inf_ll);
	
	table[0][0] = a[0][0]-val;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){			
			if(x > 0 && a[x][y] >= val+x+y){
				table[x][y] = min(table[x][y], table[x-1][y]+(a[x][y]-(val+x+y)));
			}
			if(y > 0 && a[x][y] >= val+x+y){
				table[x][y] = min(table[x][y], table[x][y-1]+(a[x][y]-(val+x+y)));
			}
		}
	}
	
	return table[n-1][m-1];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		cin >> n >> m;
		
		vector<ll> v;
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				cin >> a[x][y];
				v.push_back(a[x][y]-x-y);
			}
		}
				
		ll ans = inf_ll;
		for(int x=0;x<v.size();x++){
			if(v[x] > a[0][0]) continue;
			ans = min(ans, calc(v[x]));
		}

		cout << ans << "\n";
	}

    return 0;
}


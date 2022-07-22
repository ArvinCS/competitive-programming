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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, k;
	ll l;
	cin >> n >> l >> k;
	
	ll d[n+1];
	for(int x=0;x<n;x++){
		cin >> d[x];
	}
	d[n] = l;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	ll table[k+1][n+1];
	fill(table[0], table[k+1], 1e18);
	
	table[0][0] = 0;
	for(int x=0;x<=k;x++){
		for(int l=0;l<n;l++){
			for(int r=l+1;r<=n;r++){
				int jump = r-l-1;
				
				if(x+jump <= k){
					table[x+jump][r] = min(table[x+jump][r], table[x][l]+(d[r]-d[l])*a[l]);
				}
			}
		}
	}
	
	ll ans = 1e18;
	for(int x=0;x<=k;x++){
		ans = min(ans, table[x][n]);
	}
	
	cout << ans << "\n";
    return 0;
}


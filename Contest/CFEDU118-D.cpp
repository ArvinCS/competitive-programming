#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		ll table[n+1][3];
		fill(table[0], table[n+1], 0);
		
		for(int x=0;x<n;x++){
			table[a[x]][0] += table[a[x]][0];
			table[a[x]][0] %= mod;
			
			table[a[x]][1] += table[a[x]][1];
			table[a[x]][1] %= mod;
			
			table[a[x]][2] += table[a[x]][2];
			table[a[x]][2] %= mod;
			
			if(a[x]+2 <= n){
				table[a[x]][2] += table[a[x]+2][1];
				table[a[x]][2] %= mod;
			}
			
			if(a[x] >= 2){
				table[a[x]][1] += table[a[x]-2][0] + table[a[x]-2][2];
				table[a[x]][1] %= mod;
			}
			
			if(a[x] <= 1){
				table[a[x]][a[x]]++;
				table[a[x]][a[x]] %= mod;
			}
			
			if(a[x] >= 1){
				table[a[x]][0] += table[a[x]-1][0];
				table[a[x]][0] %= mod;
			}
		}
		
		ll ans = 0;
		for(int x=0;x<=n;x++){
			ans += table[x][0] + table[x][1] + table[x][2];
			ans %= mod;
		}
		
		cout << ans << "\n";
	}

    return 0;
}


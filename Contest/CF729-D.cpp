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

	int n;
	cin >> n;
	
	ll a[n];
	for(int x=0;x<n;x++){
		char c;
		cin >> c;
		
		if(c == '+'){
			cin >> a[x];
		} else {
			a[x] = -1;
		}
	}
	
	ll ans = 0;
	ll table[n][n+1]; // [index][small_elements]
	for(int i=0;i<n;i++){
		if(a[i] == -1) continue;
		
		fill(table[0], table[n], 0);
		
		if(a[0] == -1){
			table[0][0] = 2;
		} else {
			if(a[0] <= a[i]){
				table[0][0] = 1;
				table[0][1] = 1;
			} else {
				table[0][0] = 2;
			}
		}
		
		for(int x=1;x<n;x++){
			if(a[x] == -1){
				for(int y=0;y<n;y++){
					table[x][y] += table[x-1][y+1];
					table[x][y] %= smod;
				}
				table[x][0] += table[x-1][0];
				table[x][0] %= smod;
			} else {
				if(x < i){
					if(a[x] <= a[i]){
						for(int y=1;y<=n;y++){
							table[x][y] += table[x-1][y-1];
							table[x][y] %= smod;
						}
					} else {
						for(int y=0;y<=n;y++){
							table[x][y] += table[x-1][y];
							table[x][y] %= smod;
						}
					}
				} else if(x == i){
					for(int y=1;y<=n;y++){
						table[x][y] += table[x-1][y-1];
						table[x][y] %= smod;
					}
					continue; // cant skip this element
				} else {
					if(a[x] < a[i]){
						for(int y=2;y<=n;y++){
							table[x][y] += table[x-1][y-1];
							table[x][y] %= smod;
						}
					} else {
						for(int y=0;y<=n;y++){
							table[x][y] += table[x-1][y];
							table[x][y] %= smod;
						}
					}
				}
			}
			
			// skip this element?
			for(int y=0;y<=n;y++){
				table[x][y] += table[x-1][y];
				table[x][y] %= smod;
			}
		}
		
		for(int x=1;x<=n;x++){
			ans += table[n-1][x]*a[i] % smod;
			ans %= smod;
		}
	}
	
	cout << ans % smod << "\n";
    return 0;
}


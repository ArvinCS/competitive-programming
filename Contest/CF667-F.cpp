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

int table[205][205][205];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, k;
	cin >> n >> k;
	
	string s, t;
	cin >> s >> t;
	
	fill(*table[0], *table[n+1], -1);
	
	table[0][0][0] = 0;
	for(int x=0;x<n;x++){
		for(int i=0;i<=k;i++){
			for(int y=0;y<=x;y++){
				if(table[x][i][y] == -1) continue;
				
				if(t[0] == t[1]){ // special case
					if(s[x] == t[0]){
						table[x+1][i][y+1] = max(table[x+1][i][y+1], table[x][i][y]+y);
					} else {
						if(i+1 <= k){
							table[x+1][i+1][y+1] = max(table[x+1][i+1][y+1], table[x][i][y]+y);
						}
						table[x+1][i][y] = max(table[x+1][i][y], table[x][i][y]);
					}
					continue;	
				}
				
				if(s[x] == t[0]){
					table[x+1][i][y+1] = max(table[x+1][i][y+1], table[x][i][y]);
					if(i+1 <= k){
						table[x+1][i+1][y] = max(table[x+1][i+1][y], table[x][i][y]+y);
					}
				} else if(s[x] == t[1]){
					table[x+1][i][y] = max(table[x+1][i][y], table[x][i][y]+y);
					if(i+1 <= k){
						table[x+1][i+1][y+1] = max(table[x+1][i+1][y+1], table[x][i][y]);
					}
				} else {
					table[x+1][i][y] = max(table[x+1][i][y], table[x][i][y]);
					if(i+1 <= k){
						table[x+1][i+1][y+1] = max(table[x+1][i+1][y+1], table[x][i][y]);
						table[x+1][i+1][y] = max(table[x+1][i+1][y], table[x][i][y]+y);
					}
				}
			}
		}
	}
	
	int ans = 0;
	for(int i=0;i<=k;i++){
		for(int y=0;y<=n;y++){
			for(int z=0;z<=n-y;z++){
				ans = max(ans, table[n][i][y]);
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}


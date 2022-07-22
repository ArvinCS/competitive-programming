#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, p, m;
	cin >> n >> p >> m;
	
	int t[n];
	for(int x=0;x<n;x++){
		cin >> t[x];
	}
	
	sort(t, t+n, greater<int>());
	
	if(m == 1){
		int mx = 55;
		int table[mx][mx], new_table[mx][mx];
		fill(table[0], table[mx], -1e9);
		
		for(int x=0;x<mx;x++){
			table[x][0] = 0;
		}
		for(int z=0;z<n;z++){
			fill(new_table[0], new_table[mx], -1e9);
			
			for(int x=1;x+1<mx;x++){
				for(int y=0;y<mx;y++){
					if(table[x-1][y] < 0 || x-t[z] < 1) continue;
					cout << z << " " << x << " " << y << " .. " << x-t[z] << " " << y << " " << x-p << " ==\n";
					if(x-p > x-t[z] || (z == 0 || x-p > y)){
						new_table[x][max(y, x-t[z])] = max(new_table[x][max(y, x-t[z])], table[x-1][y]+1);
					}
				}
				for(int y=0;y<mx;y++){
					new_table[x][y] = max(new_table[x][y], new_table[x-1][y]);
				}
			}
			
			for(int x=0;x<mx;x++){
				for(int y=0;y<mx;y++){
					if(new_table[x][y] >= 0) cout << z << " " << x << " " << y << " -> " << new_table[x][y] << "\n";
					table[x][y] = new_table[x][y];
				}
			}
		}
		
		int ans = mx;
		for(int x=1;x<mx;x++){
			for(int y=0;y<mx;y++){
				if(table[x][y] == n){
					ans = min(ans, x-1);
				}
			}
		}
		
		cout << ans << "\n";
	}
    return 0;
}


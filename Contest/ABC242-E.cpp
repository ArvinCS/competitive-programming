#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		ll table[n][3][3];
		fill(*table[0], *table[n], 0);
		
		for(int x=0;x<(n+1)/2;x++){
			int mx = max((s[x] - 'A'), (s[n-1-x] - 'A'));
			int mn = min((s[x] - 'A'), (s[n-1-x] - 'A'));
			
			int l = (s[x] - 'A');
			int r = (s[n-1-x] - 'A');
			for(int y=0;y<26;y++){				
				for(int j=0;j<3;j++){
					if(y == l && y < r) table[x][0][1] += (x > 0 ? table[x-1][0][j] : (j == 0));
					if(y == l && y == r) table[x][0][j] += (x > 0 ? table[x-1][0][j] : (j == 0));
					if(y == l && y > r) table[x][0][2] += (x > 0 ? table[x-1][0][j] : (j == 0));
					
					for(int j=0;j<3;j++){
						table[x][0][j] %= mod;
					}
					
					if(y < l && y < r) table[x][1][1] += (x > 0 ? table[x-1][0][j] : (j == 0));
					if(y < l && y == r) table[x][1][j] += (x > 0 ? table[x-1][0][j] : (j == 0));
					if(y < l && y > r) table[x][1][2] += (x > 0 ? table[x-1][0][j] : (j == 0));
					
					for(int j=0;j<3;j++){
						table[x][1][j] %= mod;
					}
					
					if(y < r) table[x][1][1] += (x > 0 ? table[x-1][1][j] : 0);
					if(y == r) table[x][1][j] += (x > 0 ? table[x-1][1][j] : 0);
					if(y > r) table[x][1][2] += (x > 0 ? table[x-1][1][j] : 0);
					
					for(int j=0;j<3;j++){
						table[x][1][j] %= mod;
					}
				}
			}
		}
		
		ll ans = 0;
		for(int i=0;i<2;i++){
			for(int j=0;j<3;j++){
				if(i == 0 && j == 2) continue;
				
				ans += table[(n+1)/2-1][i][j];
				ans %= mod;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}


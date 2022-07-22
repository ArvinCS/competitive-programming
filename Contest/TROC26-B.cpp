#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	ll grid[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> grid[x][y];
		}
	}
	
	ll cnt[2];
	cnt[0] = cnt[1] = 0;
	
	int par = 0;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(grid[x][y] == -1){
				par = (x+y)%2;
			} else {
				cnt[(x+y)%2] += grid[x][y];
			}
		}
	}
	
	ll ans = cnt[par^1] - cnt[par];;
	
	if(ans < 0){
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << ans << "\n";
	}
    return 0;
}


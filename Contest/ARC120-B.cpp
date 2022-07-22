#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	char grid[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> grid[x][y];
		}
	}
	
	ll ans = 1;
	ll cnt[n+m][3];
	fill(cnt[0], cnt[n+m], 0);
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(grid[x][y] == 'R'){
				cnt[x+y][0]++;
			} else if(grid[x][y] == 'B'){
				cnt[x+y][1]++;
			} else {
				cnt[x+y][2]++;
			}
		}
	}
	
	for(int x=0;x<n+m-1;x++){
		if(cnt[x][0] > 0 && cnt[x][1] > 0){
			ans = 0;
			break;
		}
		if(cnt[x][0] == 0 && cnt[x][1] == 0){
			ans *= 2;
			ans %= mod;
		}
	}
	
	cout << ans << "\n";
    return 0;
}


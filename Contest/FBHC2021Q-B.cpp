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
//	freopen("xs_and_os_input.txt","r",stdin);
//	freopen("xs_and_os_output.txt","w",stdout);

	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int n;
		cin >> n;
		
		char grid[n][n];
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cin >> grid[x][y];
			}
		}
		
		bool row[n][2], col[n][2];
		for(int x=0;x<n;x++){
			row[x][0] = row[x][1] = false;
			for(int y=0;y<n;y++){
				if(grid[x][y] == 'X') row[x][0] = true;
				else if(grid[x][y] == 'O') row[x][1] = true;
			}
		}
		for(int y=0;y<n;y++){
			col[y][0] = col[y][1] = false;
			for(int x=0;x<n;x++){
				if(grid[x][y] == 'X') col[y][0] = true;
				else if(grid[x][y] == 'O') col[y][1] = true;
			}
		}
		
		int cnt[n][2], last[n][2]; // row/col
		fill(cnt[0], cnt[n], 0);
		fill(last[0], last[n], -1);
		
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				if(grid[x][y] != '.'){
					cnt[x][0]++;
				} else {
					last[x][0] = y;
				}
				if(grid[y][x] != '.'){
					cnt[x][1]++;
				} else {
					last[x][1] = y;
				}
			}
		}
		
		int ans = inf_int, ansCnt = 1;
		for(int x=0;x<n;x++){
			if(!row[x][1]){
				if(ans == n-cnt[x][0]) ansCnt++;
				else if(ans > n-cnt[x][0]) ansCnt = 1;
				
				ans = min(ans, n-cnt[x][0]);
			}
			if(!col[x][1]){
				if(n-cnt[x][1] == 1 && !row[last[x][1]][1] && n-cnt[last[x][1]][0] == 1) continue;
				
				if(ans == n-cnt[x][1]) ansCnt++;
				else if(ans > n-cnt[x][1]) ansCnt = 1;
				
				ans = min(ans, n-cnt[x][1]);
			}	
		}
		
		if(ans != inf_int){
			cout << "Case #" << i << ": " << ans << " " << ansCnt << "\n";
		} else {
			cout << "Case #" << i << ": " << "Impossible" << "\n";
		}
	}

    return 0;
}


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
	cin >> n >> k;
	
	int grid[n][n];
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			char tmp;
			cin >> tmp;
			
			grid[x][y] = (tmp == 'B');
		}
	}
	
	int row[n][2], col[n][2];
	for(int x=0;x<n;x++){
		row[x][0] = inf_int;
		row[x][1] = -inf_int;
		for(int y=0;y<n;y++){
			if(grid[x][y]){
				row[x][0] = min(row[x][0], y);
				row[x][1] = max(row[x][1], y);
			}
		}
		if(row[x][0] == inf_int) row[x][0] = -1;
		if(row[x][1] == -inf_int) row[x][1] = -1;
	}
	
	for(int y=0;y<n;y++){
		col[y][0] = inf_int;
		col[y][1] = -inf_int;
		for(int x=0;x<n;x++){
			if(grid[x][y]){
				col[y][0] = min(col[y][0], x);
				col[y][1] = max(col[y][1], x);
			}
		}
		if(col[y][0] == inf_int) col[y][0] = -1;
		if(col[y][1] == -inf_int) col[y][1] = -1;
	}
	
	int tmp = 0;
	for(int x=0;x<n;x++){
		if(row[x][0] == -1 && row[x][1] == -1) tmp++;
		if(col[x][0] == -1 && col[x][1] == -1) tmp++;
	}
	
	int table[n][n], ans = tmp;
	for(int x=n-k+1;x<n;x++){
		for(int y=n-k+1;y<n;y++){
			table[x][y] = 0;
		}
	}
	
	for(int y=0;y<=n-k;y++){
		int cnt = 0;
		for(int y1=y;y1<y+k;y1++){
			if(col[y1][0] >= 0 && col[y1][1] <= k-1) cnt++;
		}
		for(int x1=0;x1<k;x1++){
			if(row[x1][0] >= y && row[x1][1] <= y+k-1) cnt++;
		}
		table[0][y] = cnt;
		ans = max(ans, tmp+table[0][y]);
	}
	
	for(int x=1;x<=n-k;x++){
		for(int y=0;y<=n-k;y++){			
			int cnt = table[x-1][y];
			
			for(int y1=y;y1<y+k;y1++){
				if(col[y1][0] >= x-1 && col[y1][1] <= (x-1)+k-1){
					if(col[y1][0] < x || col[y1][1] >= x+k) cnt--;
				} else {
					if(col[y1][0] >= x && col[y1][1] <= x+k-1) cnt++;
				}
			}
			
			if(row[x-1][0] >= y && row[x-1][1] <= y+k-1) cnt--;
			if(row[x+k-1][0] >= y && row[x+k-1][1] <= y+k-1) cnt++;
			
			table[x][y] = cnt;
			ans = max(ans, tmp+table[x][y]);
		}
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar


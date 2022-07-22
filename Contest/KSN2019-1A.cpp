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
	
	int n, m;
	cin >> n >> m;
	
	int grid[n][m], cnt = 0;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			char tmp;
			cin >> tmp;
			
			grid[x][y] = (tmp - '0');
			if(grid[x][y]) cnt++;
		}
	}
	
	int sum[n][m];
	for(int x=0;x<n;x++){
		int tmp = 0;
		for(int y=0;y<m;y++){
			tmp += grid[x][y];
			sum[x][y] = tmp + (x > 0 ? sum[x-1][y] : 0);
		}
	}
	
	if(n == 1){
		int best = -1;
		for(int x=0;x<m;x++){
			if(x+cnt-1 >= m) break;
			best = max(sum[0][x+cnt-1]-(x > 0 ? sum[0][x-1] : 0), best);
		}
		
		cout << cnt-best << "\n";
		return 0;
	}

	int best = -1;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			for(int z=y;z<m;z++){
				int length = z-y+1;
				if(length > cnt) break;
				if(cnt % length == 0){
					int row = cnt/length;
					if(x+row-1 >= n) continue;
					int total = sum[x+row-1][z] - (y > 0 ? sum[x+row-1][y-1] : 0) - (x > 0 ? sum[x-1][z] : 0) + (x > 0 && y > 0 ? sum[x-1][y-1] : 0);

//					cout << x << " " << y << " " << z << " -> " << total << "\n";
					best = max(best, total);
				}
			}
		}
	}

	if(best == -1){
		cout << "-1\n";
	} else {
		cout << cnt-best << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar


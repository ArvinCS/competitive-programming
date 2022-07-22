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

int countBit(int n){
	int ans = 0;
	for(int x=0;x<=5;x++){
		if(n&(1<<x)){
			ans++;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	int grid[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			char c;
			cin >> c;
			
			grid[x][y] = (c - '0');
		}
	}
	
	if(min(n, m) > 3){
		cout << "-1\n";
		return 0;
	}
	
	int ans = inf_int;
	if(min(n, m) == 1){
		ans = 0;
	} else if(min(n, m) == 2){
		if(n <= m){
			int table[m][8];
			fill(table[0], table[m], inf_int);
			
			int cur = (2 * grid[0][0] + grid[1][0]);
			for(int x=0;x<=3;x++){
				table[0][x] = (x^cur);
			}
			
			for(int x=1;x<m;x++){
				cur = (2 * grid[0][x] + grid[1][x]);
				table[x][0] = min(table[x][0], countBit(0^cur) + min(table[x-1][1], table[x-1][2]));
				table[x][1] = min(table[x][1], countBit(1^cur) + min(table[x-1][0], table[x-1][3]));
				table[x][2] = min(table[x][2], countBit(2^cur) + min(table[x-1][0], table[x-1][3]));
				table[x][3] = min(table[x][3], countBit(3^cur) + min(table[x-1][1], table[x-1][2]));
			}
			
			for(int x=0;x<=3;x++){
				ans = min(ans, table[m-1][x]);
			}
		} else { // n > m
			int table[n][8];
			fill(table[0], table[n], inf_int);
			
			int cur = (2 * grid[0][0] + grid[0][1]);
			for(int x=0;x<=3;x++){
				table[0][x] = countBit(x^cur);
			}
			
			for(int x=1;x<n;x++){
				cur = (2 * grid[x][0] + grid[x][1]);
				table[x][0] = min(table[x][0], countBit(0^cur) + min(table[x-1][1], table[x-1][2]));
				table[x][1] = min(table[x][1], countBit(1^cur) + min(table[x-1][0], table[x-1][3]));
				table[x][2] = min(table[x][2], countBit(2^cur) + min(table[x-1][0], table[x-1][3]));
				table[x][3] = min(table[x][3], countBit(3^cur) + min(table[x-1][1], table[x-1][2]));
			}
			
			for(int x=0;x<=3;x++){
				ans = min(ans, table[n-1][x]);
			}
		}
	} else {
		if(n <= m){
			int table[m][8];
			fill(table[0], table[m], inf_int);
			
			int cur = (4 * grid[0][0] + 2 * grid[1][0] + grid[2][0]);
			for(int x=0;x<=7;x++){
				table[0][x] = countBit(x^cur);
			}
			
			for(int x=1;x<m;x++){
				cur = (4 * grid[0][x] + 2 * grid[1][x] + grid[2][x]);
				table[x][0] = min(table[x][0], countBit(0^cur) + min(table[x-1][5], table[x-1][2]));
				table[x][1] = min(table[x][1], countBit(1^cur) + min(table[x-1][4], table[x-1][3]));
				table[x][2] = min(table[x][2], countBit(2^cur) + min(table[x-1][7], table[x-1][0]));
				table[x][3] = min(table[x][3], countBit(3^cur) + min(table[x-1][6], table[x-1][1]));
				table[x][4] = min(table[x][4], countBit(4^cur) + min(table[x-1][6], table[x-1][1]));
				table[x][5] = min(table[x][5], countBit(5^cur) + min(table[x-1][7], table[x-1][0]));
				table[x][6] = min(table[x][6], countBit(6^cur) + min(table[x-1][4], table[x-1][3]));
				table[x][7] = min(table[x][7], countBit(7^cur) + min(table[x-1][5], table[x-1][2]));
			}
			
			for(int x=0;x<=7;x++){
				ans = min(ans, table[m-1][x]);
			}
		} else { // n > m
			int table[n][8];
			fill(table[0], table[n], inf_int);
			
			int cur = (2 * grid[0][0] + 2 * grid[0][1] + grid[0][2]);
			for(int x=0;x<=7;x++){
				table[0][x] = (x^cur);
			}
			
			for(int x=1;x<n;x++){
				cur = (2 * grid[x][0] + 2 * grid[x][1] + grid[x][2]);
				table[x][0] = min(table[x][0], countBit(0^cur) + min(table[x-1][5], table[x-1][2]));
				table[x][1] = min(table[x][1], countBit(1^cur) + min(table[x-1][4], table[x-1][3]));
				table[x][2] = min(table[x][2], countBit(2^cur) + min(table[x-1][7], table[x-1][0]));
				table[x][3] = min(table[x][3], countBit(3^cur) + min(table[x-1][6], table[x-1][1]));
				table[x][4] = min(table[x][4], countBit(4^cur) + min(table[x-1][6], table[x-1][1]));
				table[x][5] = min(table[x][5], countBit(5^cur) + min(table[x-1][7], table[x-1][0]));
				table[x][6] = min(table[x][6], countBit(6^cur) + min(table[x-1][4], table[x-1][3]));
				table[x][7] = min(table[x][7], countBit(7^cur) + min(table[x-1][5], table[x-1][2]));
			}
			
			for(int x=0;x<=7;x++){
				ans = min(ans, table[n-1][x]);
			}
		}
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar


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

	us t;
	cin >> t;
	
	for(us i=1;i<=t;i++){
		int grid[3][3];
		for(int x=0;x<3;x++){
			for(int y=0;y<3;y++){
				if(x == 1 && y == 1) continue;
				cin >> grid[x][y];
			}	
		}
		
		int cnt = 0;
		if(grid[0][1]-grid[0][0] == grid[0][2] - grid[0][1]) cnt++;
		if(grid[2][1]-grid[2][0] == grid[2][2] - grid[2][1]) cnt++;
		if(grid[1][0]-grid[0][0] == grid[2][0] - grid[1][0]) cnt++;
		if(grid[1][2]-grid[0][2] == grid[2][2] - grid[1][2]) cnt++;
		
		map<int, int> mp;
		if((grid[2][2]-grid[0][0]) % 2 == 0) mp[grid[0][0]+(grid[2][2]-grid[0][0])/2]++;
		if((grid[2][0]-grid[0][2]) % 2 == 0) mp[grid[0][2]+(grid[2][0]-grid[0][2])/2]++;
		if((grid[0][1]-grid[2][1]) % 2 == 0) mp[grid[2][1]+(grid[0][1]-grid[2][1])/2]++;
		if((grid[1][2]-grid[1][0]) % 2 == 0) mp[grid[1][0]+(grid[1][2]-grid[1][0])/2]++;
		
		int ans = cnt;
		for(auto m : mp){
			grid[1][1] = m.first;
//			cout << m.first << " " << cnt << "\n";
			int best = cnt;
			if(grid[1][1]-grid[0][0] == grid[2][2] - grid[1][1]) best++;
			if(grid[1][1]-grid[0][2] == grid[2][0] - grid[1][1]) best++;
			if(grid[1][1]-grid[1][0] == grid[1][2] - grid[1][1]) best++;
			if(grid[1][1]-grid[0][1] == grid[2][1] - grid[1][1]) best++;
			
			ans = max(ans, best);
		}
		
		cout << "Case #" << i << ": " << ans << "\n";
	}

    return 0;
}


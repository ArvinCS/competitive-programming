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

	us t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int r, c;
		cin >> r >> c;
		
		priority_queue<pair<int, pair<int, int>>> pq;
		int grid[r][c];
		for(int x=0;x<r;x++){
			for(int y=0;y<c;y++){
				cin >> grid[x][y];
				pq.push(make_pair(grid[x][y], make_pair(x, y)));
			}
		}
		
		ll ans = 0;
		while(!pq.empty()){
			pair<int, pair<int, int>> p = pq.top();
			pq.pop();
			
			int x = p.second.first, y = p.second.second;
			int height = p.first;
			
			if(height != grid[x][y]) continue;
			
			if(x-1 >= 0 && grid[x-1][y]+1 < height){
				int tmp = (height-1)-grid[x-1][y];
				ans += tmp;
				grid[x-1][y] += tmp;
				
				pq.push(make_pair(grid[x-1][y], make_pair(x-1, y)));
			}
			if(x+1 < r && grid[x+1][y]+1 < height){
				int tmp = (height-1)-grid[x+1][y];
				ans += tmp;
				grid[x+1][y] += tmp;
				
				pq.push(make_pair(grid[x+1][y], make_pair(x+1, y)));
			}
			
			if(y-1 >= 0 && grid[x][y-1]+1 < height){
				int tmp = (height-1)-grid[x][y-1];
				ans += tmp;
				grid[x][y-1] += tmp;
				
				pq.push(make_pair(grid[x][y-1], make_pair(x, y-1)));
			}
			if(y+1 < c && grid[x][y+1]+1 < height){
				int tmp = (height-1)-grid[x][y+1];
				ans += tmp;
				grid[x][y+1] += tmp;
				
				pq.push(make_pair(grid[x][y+1], make_pair(x, y+1)));
			}
		}
		
//		for(int x=0;x<r;x++){
//			for(int y=0;y<c;y++){
//				cout << grid[x][y];
//			}
//			cout << "\n";
//		}
		cout << "Case #" << i << ": " << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar


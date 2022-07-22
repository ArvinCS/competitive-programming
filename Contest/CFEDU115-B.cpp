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
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		bool grid[n][5];
		for(int x=0;x<n;x++){
			for(int y=0;y<5;y++){
				char c;
				cin >> c;
				
				grid[x][y] = (c == '1');
			}
		}
		
		bool possible = false;
		for(int a=0;a<5;a++){
			for(int b=a+1;b<5;b++){
				int cnt[3];
				fill(cnt, cnt+3, 0);
				
				for(int x=0;x<n;x++){
					if(grid[x][a] && grid[x][b]){
						cnt[2]++;
						continue;
					}
					
					if(grid[x][a]){
						cnt[0]++;
					}
					if(grid[x][b]){
						cnt[1]++;
					}
				}
				
				if(cnt[0]+cnt[1]+cnt[2] == n && abs(cnt[0]-cnt[1]) <= cnt[2]){
					possible = true;
					break;
				}
			}
			if(possible) break;
		}
		
		if(possible){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}


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
		int n, m;
		cin >> n >> m;
		
		vector<pair<int, int>> v;
		int a[n][m];
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				cin >> a[x][y];
			}
			v.push_back({a[x][0], x});
		}
		
		sort(v.begin(), v.end());
		
		int prefix[n][m][2], suffix[n][m][2];
		prefix[0][0][0] = suffix[0][m-1][0] = inf_int;
		prefix[0][0][1] = suffix[0][m-1][1] = -1;
		
		for(int y=0;y<m;y++){
			for(int x=0;x<n;x++){
				prefix[x][y][0] = prefix[x][y][1] = a[v[x].second][y];
				if(y > 0){
					prefix[x][y][0] = min(prefix[x][y][0], prefix[x][y-1][0]);
					prefix[x][y][1] = max(prefix[x][y][1], prefix[x][y-1][1]);
				}
			}
		}
		for(int y=m-1;y>=0;y--){
			for(int x=0;x<n;x++){
				suffix[x][y][0] = suffix[x][y][1] = a[v[x].second][y];
				if(y < m-1){
					suffix[x][y][0] = min(suffix[x][y][0], suffix[x][y+1][0]);
					suffix[x][y][1] = max(suffix[x][y][1], suffix[x][y+1][1]);
				}
			}
		}
		
		string ans(n, '?');
		int l = -1;
		
		for(int y=0;y<m-1;y++){
			if(l >= 0) break;
			
			int mx[n], mn[n];
			mx[0] = prefix[0][y][1];
			mn[0] = suffix[0][y+1][0];
			for(int x=1;x<n;x++){
				mx[x] = max(mx[x-1], prefix[x][y][1]);
				mn[x] = min(mn[x-1], suffix[x][y+1][0]);
			}
			
			int curMin = inf_int, curMx = 0;
			for(int x=n-1;x>=1;x--){
				curMin = min(curMin, prefix[x][y][0]);
				curMx = max(curMx, suffix[x][y+1][1]);
				
				if(mx[x-1] < curMin && mn[x-1] > curMx){
					l = y;
					for(int z=0;z<n;z++){
						if(z < x) ans[v[z].second] = 'B';
						else ans[v[z].second] = 'R';
					}
					break;
				}
			}
		}
		
		if(l >= 0){
			cout << "YES\n";
			cout << ans << " " << l+1 << "\n";
		} else {
			cout << "NO\n";
		}
	}

    return 0;
}


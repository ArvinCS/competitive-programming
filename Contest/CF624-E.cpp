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
		int n, d;
		cin >> n >> d;
		
		int parrent[n], sz[n], depth[n];
				
		parrent[0] = 0;
		depth[0] = 0;
		sz[0] = 0;
		
		for(int x=1;x<n;x++){
			parrent[x] = (x-1)/2;
			depth[x] = depth[parrent[x]] + 1;
			sz[parrent[x]]++;
			sz[x] = 0;
			
			d -= depth[x];
		}
		
		for(int x=n-1;x>=1;x--){
			if(sz[x] == 0){
				for(int y=n-1;y>=0;y--){
					if(x == y) continue;
					if(sz[y] < 2 && d-(depth[y]+1)+depth[x] >= 0 && depth[y]+1 > depth[x]){
						sz[parrent[x]]--;
						d += depth[x];
						
						parrent[x] = y;
						sz[parrent[x]]++;
						depth[x] = depth[parrent[x]] + 1;
						d -= depth[x];
					}
				}
			}
		}
		
		if(d != 0){
			cout << "NO\n";
			continue;
		}
		
		cout << "YES\n";
		for(int x=1;x<n;x++){
			if(x > 1) cout << " ";
			cout << parrent[x]+1;
		}
		cout << "\n";
	}

    return 0;
}


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
	
	int t = 3 * (1 << k);
	
	while(t--){
		int color[n];
		for(int x=0;x<n;x++){
			color[x] = ()
		}
		ll cost[n][n], dist[n][k+1];
		int mn[n];
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cin >> cost[x][y];
			}
		}
		
		fill(dist[0], dist[n], inf_ll);
		fill(mn, mn+n, inf_int);
		
		dist[0][0] = 0;
		for(int z=1;z<=k;z++){
			for(int x=0;x<n;x++){
				for(int y=0;y<n;y++){
					if(x == y) continue;
					
					if(dist[y][z] > dist[x][z-1]+cost[x][y] && (mn[y] == inf_int || (z-mn[y])%2 == 0)){
						dist[y][z] = dist[x][z-1]+cost[x][y];
						mn[y] = min(mn[y], z);
						cout << y << " " << z << " " << dist[y][z] << " == " << x << "\n";
					}
				}
			}
		}
		
		ll ans = inf_ll;
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				if(a == b) continue;
				
				for(int z=0;z<k/2;z++){
					if(dist[a][z] == inf_ll) continue;
					
					ll val = dist[a][z] + (k-2*z)/2 * (cost[a][b]+cost[b][a]);
					cout << a << " " << b << " " << z << " -> " << val << " " << (k-2*z)/2 << "\n";
					ans = min(ans, val);
				}
			}
		}
		
		cout << ans << "\n";
	}
    return 0;
}


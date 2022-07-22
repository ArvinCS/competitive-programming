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
	
	int t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}	
		
		int dist[n];
		for(int x=0;x<n;x++){
			dist[x] = (x+1-a[x]);
		}
		
		int cnt[n], move[n];
		fill(cnt, cnt+n, 0);
		fill(move, move+n, 0);
		
		for(int i=0;i<k;i++){
			for(int x=i;x<n;x++){
				int mx = 0, mx2 = inf_int;
				for(int y=0;y<x;y++){
					if(y-dist[y] >= x-dist[x]) continue;
					
					if((cnt[y] == mx && mx2 > move[y]) || cnt[y] > mx){
						if(mx2 > move[y]){
							
						}
					}
				}
				
				cnt[x] = mx+1;
			}
		}
		
		for(int x=0;x<n;x++){
			cout << cnt[x] << " ";
		}
		cout << "\n";
		
		int ans = -1;
		for(int x=0;x<n;x++){
			if(cnt[x] >= k){
				ans = x+1-k;
				break;
			}
		}
		
		cout << ans << "\n";
	}

    return 0;
}


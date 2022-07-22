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
	
	int n, k;
	cin >> n >> k;
	
	int cur[4];
	for(int x=0;x<4;x++){
		cin >> cur[x];
	}
	
	bool mat[k+1][k+1];
	for(int x=1;x<=k;x++){
		for(int y=1;y<=k;y++){
			char tmp;
			cin >> tmp;
			
			mat[x][y] = (tmp - '0');
		}
	}
	
	pair<int, int> room[n];
	for(int x=0;x<n;x++){
		cin >> room[x].first;
		if(room[x].first == 1){
			cin >> room[x].second;
		} else {
			room[x].second = 0;
		}
	}
	
	int suffix[n][k+1];
	fill(suffix[0], suffix[n], 0);
	
	suffix[n-1][room[n-1].second]++;
	for(int x=n-2;x>=0;x--){
		if(room[x].first == 1){
			for(int i=1;i<=k;i++){
				suffix[x][i] = suffix[x+1][i];
			}
			suffix[x][room[x].second]++;
		}
	}
	
//	for(int x=0;x<n;x++){
//		for(int y=1;y<=k;y++){
//			cout << suffix[x][y];
//		}
//		cout << "\n";
//	}
	
	ll ans = 0;
	for(int x=0;x<n;x++){
//		cout << x << "\n";
		if(room[x].first == 1){
			for(int i=0;i<4;i++){
				if(mat[cur[i]][room[x].second]){
					ans++;
					break;
				}
			}
		} else {
			int last = x+1;
			while(last < n){
				if(room[last].first == 2) last++;
				else break;
			}
			
			if(last == n) break;
			
			int best[4];
			int bestcnt = -1;
			for(int z=1;z<=k;z++){
				for(int j=0;j<4;j++){
					if(mat[cur[j]][z]){
						bestcnt += suffix[last][z];
						break;
					}
				}
			}
			for(int i=0;i<4;i++) best[i] = cur[i];
			
			for(int i=0;i<4;i++){
				int tmp[4];
				for(int y=0;y<4;y++) tmp[y] = cur[y];
				
				for(int y=1;y<=k;y++){
					bool valid = true;
					for(int z=0;z<4;z++){
						if(z == i) continue;
						if(y == tmp[z]){
							valid = false;
							break;
						}
					}
					if(!valid) continue;
					
					int cnt = 0;
					tmp[i] = y;
					for(int z=1;z<=k;z++){
						for(int j=0;j<4;j++){
							if(mat[tmp[j]][z]){
								cnt += suffix[last][z];
								break;
							}
						}
					}
					if(cnt > bestcnt){
						for(int z=0;z<4;z++) best[z] = tmp[z];
						bestcnt = cnt;
					}
				}
			}
//			cout << bestcnt << "\n";
			for(int i=0;i<4;i++) cur[i] = best[i];
		}
//		for(int x=0;x<4;x++) cout << cur[x] << " ";
//		cout << "\n";
//		cout << ans << "\n";
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar


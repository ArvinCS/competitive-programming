#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;
const int maxLogK = 60;

vector<int> adj[maxN];
ll a[maxN], b[maxN];
pair<ll, int> binlift[maxLogK][maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	ll k;
	cin >> n >> m >> k;
	
	for(int x=0;x<n;x++){
		cin >> a[x];
		b[x] = 0;
	}
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
	}
	
	fill(binlift[0], binlift[maxLogK], make_pair(1e18, -1));
	
	k--;
	
	for(int x=0;x<n;x++){
		for(auto nxt : adj[x]){
			binlift[0][x] = min(binlift[0][x], {a[nxt], nxt});
		}
	}
	if(k&1){
		for(int x=0;x<n;x++){
			if(binlift[0][x].second == -1){
				b[x] = 1e18;
				continue;
			}
			
			b[x] = binlift[0][x].first;
		}
	}
	
	for(int i=1;i<maxLogK;i++){
		for(int x=0;x<n;x++){
			for(auto nxt : adj[x]){
				// 2^i - 1 = 
				int nxt2 = nxt;
				ll val = a[nxt];
				for(int j=i-2;j>=0;j--){
					if(binlift[j][nxt2].second == -1){
						nxt2 = -1;
						break;
					}
					
					val = max(val, binlift[j][nxt2].first);
					nxt2 = binlift[j][nxt2].second;
				}
				
				if(nxt2 == -1) continue;
				if(binlift[i-1][nxt2].second == -1) continue;
				
				int nxt3 = binlift[i-1][nxt2].second;
				ll val2 = 0;
				for(int j=i-1;j>=0;j--){
					if(k&(1ll << j)){
						val2 = max(val2, binlift[j][nxt3].first);
						nxt3 = binlift[j][nxt3].second;
					}
				}
				
//				cout << i << " " << x << " " << nxt << " " << nxt2 << " " << nxt3 << "\n";
				binlift[i][x] = min(binlift[i][x], {max({val, binlift[i-1][nxt2].first, val2}), binlift[i-1][nxt2].second});
			}
		}
	}
	
	ll ans = 1e18;
	for(int x=0;x<n;x++){
		if(b[x] != 1e18){
			int nxt3 = binlift[i-1][nxt2].second;
			ll val2 = 0;
			for(int j=i-1;j>=0;j--){
				if(k&(1ll << j)){
					val2 = max(val2, binlift[j][nxt3].first);
					nxt3 = binlift[j][nxt3].second;
				}
			}
			
			ans = min(ans, max(val2, a[x]));
		}
	}
	
	if(ans == 1e18){
		cout << "-1\n";
	} else {
		cout << ans << "\n";
	}
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxM = 16;
const int maxMBit = (1 << maxM);

int n, m;
ll cnt[maxM][maxMBit];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(cnt[0], cnt[maxM], 0);
	
	cin >> n >> m;
	
	int a[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> a[x][y];
		}
	}
	
	int b[m];
	for(int x=0;x<m;x++){
		cin >> b[x];
	}
	
	for(int x=0;x<n;x++){
		vector<pair<int, int>> v;
		for(int y=0;y<m;y++){
			v.push_back({a[x][y], y});
		}
		
		sort(v.begin(), v.end());
		
		int bit = 0;
		for(int y=0;y<m;y++){
			cnt[v[y].second][bit] += v[y].first;
			bit |= (1 << v[y].second);
		}
	}
	
	for(int x=0;x<m;x++){
		for(int i = 0;i < m; ++i){
			for(int mask = 0; mask < (1<<m); ++mask){
				if(mask & (1<<i)){
					cnt[x][mask] += cnt[x][mask^(1<<i)];					
				}
			}
		}
	}
	
	ll fullbit = (1 << m)-1;
	ll ans = 1e18;
	for(int state=1;state<(1 << m);state++){
		ll val = 0;
		for(int x=0;x<m;x++){
			int bit = (1 << x);
			
			if(state&bit){
				val += b[x] + cnt[x][fullbit^state];
			}
		}
		
		ans = min(ans, val);
	}
	
	cout << ans << "\n";
    return 0;
}


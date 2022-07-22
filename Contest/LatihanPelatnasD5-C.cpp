#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 20;
const int maxM = 5e3 + 5;

int n, m;
int a[maxM][maxN];
vector<pair<int, int>> v;
int new_c[2][maxN];
ll mx[2] = {-1, -1};

void solve(int idx, int bound, int id, int c[]){
	if(idx >= bound){
		ll sum = 0;
		for(int x=0;x<n;x++){
			sum += c[x];
		}
		
		if(sum > mx[id]){
			mx[id] = sum;
			for(int x=0;x<n;x++){
				new_c[id][x] = c[x];
			}
		}
		return;
	}
	
	for(int x=0;x<n;x++){
		int new_c[n];
		for(int y=0;y<n;y++){
			new_c[y] = max(c[y], a[v[idx].second][(x+y)%n]);
		}
		
		solve(idx+1, bound, id, new_c);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		for(int y=0;y<n;y++){
			cin >> a[x][y];
		}
	}
	
	for(int x=0;x<m;x++){
		int mx = 0;
		for(int y=0;y<n;y++){
			mx = max(mx, a[x][y]);
		}
		v.push_back({mx, x});
	}
	
	sort(v.rbegin(), v.rend());
	
	int mid = min(m, n)/2;
	int c[n];
	fill(c, c+n, 0);
	
	for(int x=0;x<n;x++){
		c[x] = a[v[0].second][x];
	}
	
	solve(1, mid, 0, c);
	
	fill(c, c+n, 0);
	
	if(mid < m){
		for(int x=0;x<n;x++){
			c[x] = a[v[mid].second][x];
		}
		
		solve(mid+1, min(n, m), 1, c);
	}
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			ll sum = 0;
			for(int z=0;z<n;z++){
				sum += max(new_c[0][(x+z)%n], new_c[1][(y+z)%n]);
			}
			ans = max(ans, sum);
		}
	}
	cout << ans << "\n";
	return 0;
}

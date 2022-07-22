#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 998244353

const int maxN = 1005;
const int maxK = 100005;

vector<pair<int, int>> adj[maxN];
int cnt[maxN], dist[maxN];
ll table[maxN][maxK];
pair<int, int> parrent[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	int a[m];
	for(int x=0;x<m;x++){
		cin >> a[x];
		a[x]--;
	}
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		
		cnt[x] = 0;
		adj[a].push_back({b, x});
		adj[b].push_back({a, x});
	}
	
	fill(cnt, cnt+n, 0);
	
	for(int x=0;x+1<m;x++){
		fill(dist, dist+n, inf_int);
		
		queue<pair<int, int>> q;
		dist[a[x]] = 0;
		q.push({dist[a[x]], a[x]});
		
		while(!q.empty()){
			pair<int, int> p = q.front();
			q.pop();
			
			if(dist[p.second] < p.first) continue;
			for(auto nxt : adj[p.second]){
				if(dist[nxt.first] > dist[p.second]+1){
					dist[nxt.first] = dist[p.second]+1;
					parrent[nxt.first] = {p.second, nxt.second};
					
					q.push({dist[nxt.first], nxt.first});
				}
			}
		}
		
		int node = a[x+1];
		while(node != a[x]){
			cnt[parrent[node].second]++;
			node = parrent[node].first;
		}
	}
	
	fill(table[0], table[n], 0);
	table[0][0]++;
	table[0][cnt[0]]++;
	
	int sum = cnt[0];
	for(int x=1;x<n-1;x++){
		sum += cnt[x];
		
		for(int y=0;y<maxK;y++){
			if(y+cnt[x] < maxK){
				table[x][y+cnt[x]] += table[x-1][y];
				table[x][y+cnt[x]] %= mod;
			}
			table[x][y] += table[x-1][y];
			table[x][y] %= mod;
		}
	}
	
	ll ans = 0;
	for(int x=0;x<maxK;x++){
		int y = sum-x;
		
		if(x-y == k){
			ans += table[n-2][x];
			ans %= mod;
		}
	}
	
	cout << ans << "\n";
    return 0;
}


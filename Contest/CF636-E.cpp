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

const int maxN = 2e5 + 5;

vector<pair<int, int>> adj[maxN];
pair<int, int> edge[maxN];
ll p[maxN], n, m;

void bfs(int startNode, vector<int> &dist){
	queue<pair<int, int>> q;
	fill(dist.begin(), dist.end(), inf_int);
	
	dist[startNode] = 0;
	q.push({dist[startNode], startNode});
	
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		
		if(dist[p.second] < p.first) continue;
		for(auto nxt : adj[p.second]){
			if(dist[nxt.first] > dist[p.second]+1){
				dist[nxt.first] = dist[p.second]+1;
				q.push({dist[nxt.first], nxt.first});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		int a, b, c;
		cin >> n >> m >> a >> b >> c;
		
		a--; b--; c--;
		for(int x=0;x<n;x++) adj[x].clear();
		p[0] = 0;
		for(int x=1;x<=m;x++){
			cin >> p[x];
		}
		
		for(int x=0;x<m;x++){
			cin >> edge[x].first >> edge[x].second;
			
			edge[x].first--; edge[x].second--;
			adj[edge[x].first].push_back({edge[x].second, x});
			adj[edge[x].second].push_back({edge[x].first, x});
		}
		
		sort(p, p+m+1);
		
		for(int x=1;x<=m;x++){
			p[x] += p[x-1];
		}
		
		vector<int> distA(n), distB(n), distC(n);
		bfs(a, distA);
		bfs(b, distB);
		bfs(c, distC);
		
		ll ans = inf_ll;
		for(int x=0;x<n;x++){
			if(distA[x]+distB[x]+distC[x] > m) continue;
			
			ll dist = p[distB[x]] + p[distA[x]+distB[x]+distC[x]];
			ans = min(ans, dist);
		}
		cout << ans << "\n";
	}

    return 0;
}


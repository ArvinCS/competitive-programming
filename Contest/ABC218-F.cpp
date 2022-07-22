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

const int maxN = 405;

vector<pair<int, int>> adj[maxN];
int edge[maxN][maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back({b, x});
		edge[a][b] = x;
	}
	
	int dist[n], backtrack[n];
	fill(dist, dist+n, inf_int);
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[0] = 0;
	backtrack[0] = -1;
	pq.push({dist[0], 0});
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		
		if(dist[p.second] < p.first) continue;
		for(auto nxt : adj[p.second]){
			if(dist[nxt.first] > p.first+1){
				dist[nxt.first] = p.first+1;
				backtrack[nxt.first] = p.second;
				pq.push({dist[nxt.first], nxt.first});
			}
		}
	}
	
	bool used[m];	
	fill(used, used+m, false);
	
	if(dist[n-1] != inf_int){		
		int curNode = n-1;
		while(curNode > 0){
			used[edge[backtrack[curNode]][curNode]] = true;
			curNode = backtrack[curNode];
		}
	}
	
	int ans = (dist[n-1] != inf_int ? dist[n-1] : -1);
	for(int x=0;x<m;x++){
		if(!used[x]){
			cout << ans << "\n";
			continue;
		}
		
		fill(dist, dist+n, inf_int);
		
		dist[0] = 0;
		pq.push({dist[0], 0});
		
		while(!pq.empty()){
			pair<int, int> p = pq.top();
			pq.pop();
			
			if(dist[p.second] < p.first) continue;
			for(auto nxt : adj[p.second]){
				if(nxt.second != x && dist[nxt.first] > p.first+1){
					dist[nxt.first] = p.first+1;
					backtrack[nxt.first] = p.second;
					pq.push({dist[nxt.first], nxt.first});
				}
			}
		}
		
		cout << (dist[n-1] != inf_int ? dist[n-1] : -1) << "\n";
	}
	
    return 0;
}


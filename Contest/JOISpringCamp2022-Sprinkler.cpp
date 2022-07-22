#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;
const int maxM = 4e5 + 5;
const int logN = log2(maxN)+1;
const int sz = 634;

vector<int> adj[maxN];
int parent[logN][maxN], level[maxN];

void dfs(int curNode, int prvNode){
	for(int i=1;i<logN;i++){
		parent[i][curNode] = parent[i-1][parent[i-1][curNode]];
	}
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			level[nxt] = level[curNode]+1;
			parent[0][nxt] = curNode;
			dfs(nxt, curNode);
		}
	}
}

int findLCA(int a, int b){
	if(level[a] > level[b]) swap(a, b);
	
	for(int x=logN-1;x>=0;x--){
		if(level[a] <= level[b]-(1 << x)){
			b = parent[x][b];
		}
	}
	
	if(a == b) return a;
	
	for(int x=logN-1;x>=0;x--){
		if(parent[x][a] != parent[x][b]){
			a = parent[x][a];
			b = parent[x][b];
		}
	}
	
	return parent[0][a];
}

int getDist(int a, int b){
	return level[a]+level[b]-2*level[findLCA(a, b)];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll l;
	cin >> n >> l;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	ll h[n];
	for(int x=0;x<n;x++){
		cin >> h[x];
	}
	
	parent[0][0] = level[0] = 0;
	dfs(0, 0);
	
	vector<tuple<int, int, ll>> pending;
	
	int q;
	cin >> q;
	
	for(int x=0;x<q;x++){
		int t;
		cin >> t;
		
		if(t == 1){
			int node, d;
			ll w;
			cin >> node >> d >> w;
			
			node--;
			queue<array<int, 3>> q;
			q.push({0, node, node});
			
			while(!q.empty()){
				array<int, 3> p = q.front();
				q.pop();
				
				h[p[1]] *= w;
				h[p[1]] %= l;
				
				if(p[0] >= d) continue;
				for(auto nxt : adj[p[1]]){
					if(nxt != p[2]){
						q.push({p[0]+1, nxt, p[1]});
					}
				}
			}
			
//			pending.push_back(make_tuple(node, d, w));
//			
//			if(pending.size() >= sz){
//				for(int x=0;x<n;x++){
//					for(auto t : pending){
//						if(getDist(x, get<0>(t)) <= get<1>(t)){
//							h[x] *= get<2>(t);
//							h[x] %= l;
//						}
//					}
//				}
//				
//				pending.clear();
//			}
		} else if(t == 2){
			int node;
			cin >> node;
			
			node--;
			
			ll ans = h[node];
//			for(auto t : pending){
//				if(getDist(node, get<0>(t)) <= get<1>(t)){
//					ans *= get<2>(t);
//					ans %= l;
//				}
//			}
			
			cout << ans << "\n";
		} else {
			assert(false);
		}
	}
    return 0;
}


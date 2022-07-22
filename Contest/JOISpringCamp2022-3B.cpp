#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
const int maxN = 2e5 + 5;
const int maxD = 45;
 
ll l;

vector<int> adj[maxN];
ll val[maxN][maxD];
int level[maxN];
int parent[maxN];
 
void dfs(int curNode, int prvNode = 0){
	parent[curNode] = prvNode;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			level[nxt] = level[curNode]+1;
			dfs(nxt, curNode);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
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
	
	level[0] = 0;
	dfs(0, -1);
	
	fill(val[0], val[maxN], 1);
	
	int q;
	cin >> q;
	
	while(q--){
		int t;
		cin >> t;
		
		if(t == 1){
			int x, d, w;
			cin >> x >> d >> w;
			
			x--;
			
			int node = x;
			while(node != 0 && d >= 0){
				val[node][d] *= w;
				val[node][d] %= l;
				
				d--;
				node = parent[node];
			}
			if(d >= 0){
				for(int x=0;x<min(d+1, maxD);x++){
					val[0][x] *= w;
					val[0][x] %= l;
				}
			}
			
		} else if(t == 2){
			int x;
			cin >> x;
			
			x--;
			
			ll ans = h[x];
			int d = 0;
			int node = x;
			
			while(node != -1 && d <= 40){
				ans *= val[node][d];
				ans %= l;
				
				if(node != 0 && d < 40) ans *= val[node][d+1];
				ans %= l;
				
				d++;
				node = parent[node];
			}
			
			cout << ans << "\n";
		} else {
			assert(false);
		}
	}
    return 0;
}

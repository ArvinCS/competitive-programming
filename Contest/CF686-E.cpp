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

vector<int> adj[maxN];
int color[maxN], sz[maxN], parrent[maxN], n;
bool cycle[maxN];

void dfs(int curNode, int prvNode){
	if(color[curNode] == 2){
		return;
	}
	if(color[curNode] == 1){
		int cur = prvNode;
		cycle[curNode] = true;
		
		while(cur != curNode){
			cycle[cur] = true;
			cur = parrent[cur];
		}
		return;
	}
	
	parrent[curNode] = prvNode;
	color[curNode] = 1;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode);
		}
	}
	
	color[curNode] = 2;
}

void dfs2(int curNode, int prvNode){
	sz[curNode] = 1;
	
	for(auto nxt : adj[curNode]){
		if(!cycle[nxt] && nxt != prvNode){
			dfs2(nxt, curNode);
			sz[curNode] += sz[nxt];
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
		cin >> n;
		
		for(int x=0;x<n;x++){
			adj[x].clear();
			color[x] = 0;
			parrent[x] = x;
			cycle[x] = false;
			sz[x] = 0;
		}
		
		for(int x=0;x<n;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		dfs(0, 0);
		
		for(int x=0;x<n;x++){
			if(cycle[x]){
				dfs2(x,x);
			}
		}
		
		ll ans = 0;
		for(int x=0;x<n;x++){
			if(cycle[x]){
				ans += sz[x]*1ll*(sz[x]-1);
				
				int remain = n-sz[x];
				ans += remain*1ll*sz[x]*2;
			}
		}
		cout << ans/2 << "\n";
	}

    return 0;
}


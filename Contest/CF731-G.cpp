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

const int maxN = 4e5 + 5;

vector<pair<int, int>> mark[3]; // 0 multiple path, 1 self loop, 2 cycle
vector<int> adj[maxN];
int ans[maxN];

void dfs(int curNode, bool visited[], bool cur[]){
	visited[curNode] = true;
	cur[curNode] = true;
		
	for(auto nxt : adj[curNode]){
		if(nxt != curNode){
			if(visited[nxt]){
				if(cur[nxt]){
					mark[2].push_back({nxt, 2});
				} else {
					mark[0].push_back({nxt, 1});
				}
			} else {
				dfs(nxt, visited, cur);
			}
		} else {
			mark[1].push_back({nxt, 0});
		}
	}
	
	cur[curNode] = false;
}

void dfs2(int id, int curNode, bool visited[]){
	if(id == -1){
		ans[curNode] = 1;
	} else if(id == 0){
		ans[curNode] = 2;
	} else if(id == 2){
		ans[curNode] = -1;
	} else if(id == 1){
		ans[curNode] = -1;
	}
	
//	cout << id << " " << curNode << "\n";
	visited[curNode] = true;
	for(auto nxt : adj[curNode]){
		if(!visited[nxt]){
			dfs2(id, nxt, visited);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		for(int x=0;x<n;x++) adj[x].clear();
		for(int x=0;x<3;x++) mark[x].clear();
		for(int x=0;x<m;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
		}
		
		bool visited[n], cur[n];
		for(int x=0;x<n;x++){
			visited[x] = cur[x] = false;
		}
		
		dfs(0, visited, cur);
		
		for(int x=0;x<n;x++){
			ans[x] = 0;
		}
		
		fill(visited, visited+n, false);
		dfs2(-1, 0, visited);
		
		for(int id=0;id<3;id++){
			fill(visited, visited+n, false);
			
			for(auto p : mark[id]){
//				cout << p.first << "\n";
				dfs2(id, p.first, visited);
			}
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}

    return 0;
}


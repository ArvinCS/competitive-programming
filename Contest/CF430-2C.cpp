#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<pair<int, int>> adj[maxN];
int a[maxN], depth[maxN], parent[maxN];
set<int> st[maxN][2];

void dfs(int curNode, int prvNode){
	parent[curNode] = prvNode;
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			depth[nxt.first] = depth[curNode]+1;
			dfs(nxt.first, curNode);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back({b, 0});
		adj[b].push_back({a, 0});
	}
	
	depth[0] = 0;
	dfs(0, 0);
	
	vector<int> v[n];
	for(int x=0;x<n;x++){
		v[depth[x]].push_back(x);
		
		if(x != 0){
			for(auto nxt : adj[x]){
				if(nxt.first != parent[x] && nxt.second == 0){
					adj[parent[x]].push_back({nxt.first, 1});
				}
			}
		}
	}
	
	st[0][0].insert(a[0]);
	for(auto nxt : adj[0]){
		if(nxt.second == 0){
			st[nxt.first][1].insert(a[nxt.first]);
		}
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<2;y++){
			for(auto curNode : v[x]){
				for(auto val : st[curNode][y]){
					for(auto nxt : adj[curNode]){
						if(nxt.first == parent[curNode]) continue;
						if(y+nxt.second > 1) continue;
						
						st[nxt.first][y+nxt.second].insert(__gcd(a[nxt.first], val));
					}
				}
			}
		}
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		
		int ans = max(st[x][0].empty() ? 0 : *(st[x][0].rbegin()), st[x][1].empty() ? 0 : *(st[x][1].rbegin()));
		if(parent[x] != x){
			ans = max(ans, st[parent[x]][0].empty() ? 0 : *(st[parent[x]][0].rbegin()));
		}
		cout << ans;
	}
	cout << "\n";
    return 0;
}


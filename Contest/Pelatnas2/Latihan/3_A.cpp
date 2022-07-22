#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e3 + 5;

vector<int> adj[maxN];
vector<int> cur_adj[maxN];
bool mark[maxN][maxN], need[maxN];
int color[maxN], idx = 0;
vector<int> part[2][maxN][2];

bool dfs(int curNode, int c1, int c2){
	bool ans = true;
	need[curNode] = false;
	color[curNode] = c1;
	part[mark[curNode][1]][idx][c1].push_back(curNode);
	
	for(auto nxt : cur_adj[curNode]){
		if(color[nxt] != -1){
			ans &= (color[nxt] != color[curNode]);
		} else {
			dfs(nxt, c2, c1);
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	fill(mark[0], mark[n], false);
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		
		mark[b][a] = true;
		mark[a][b] = true;
	}	
	
	m *= 2;
	
	vector<int> ans[2];
	vector<int> part[2][2];
	
	bool possible = true;
	int sz[2];
	
	for(int i=0;i<2;i++){
		vector<int> v;
		for(int x=0;x<n;x++){
			if(mark[x][i]){
				v.push_back(x);
			}
		}
		
		for(int x=0;x<n;x++) cur_adj[x].clear();
		
		fill(need, need+n, false);
		
		for(int x=0;x<v.size();x++){
			for(int y=x+1;y<v.size();y++){
				if(!mark[v[x]][v[y]]){
					need[v[x]] = need[v[y]] = true;
					cur_adj[v[x]].push_back(v[y]);
					cur_adj[v[y]].push_back(v[x]);
				}
			}
		}
		
		fill(color, color+n, -1);
		
		idx = 0;
		for(int x=0;x<n;x++){
			if(need[x] && color[x] == -1){
				if(!dfs(i, 0, 1)){
					possible = false;
					break;
				}
				
				idx++;
			}
		}
		
		sz[i] = idx;
		ans[i].push_back(i);
		for(int x=2;x<n;x++){
			if(color[x] != -1){
				part[i][color[x]].push_back(x);
			} else {
				if(mark[x][i]){
					m -= adj[x].size();
					ans[i].push_back(x);
				}
			}
		}
	}
	
	if(!possible){
		cout << "impossible\n";
		return 0;
	}
	
	possible = false;
	
	bool dp[2][n+1][m+1];
	fill(*dp[0], *dp[2], false);
	
	for(int i=0;i<2;i++){
		dp[i][0][m] = true;
		
		for(int x=0;x<sz[i];x++){
			
		}
	}
	
	if(!possible){
		cout << "impossible\n";
		return 0;
	}
	
	for(int i=0;i<2;i++){
		for(int x=0;x<ans[i].size();x++){
			if(x > 0) cout << " ";
			cout << ans[i][x]+1;
		}
		cout << "\n";
	}
    return 0;
}


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

const int maxNM = 1e6 + 5;

int parrent[maxNM];
int c[maxNM], visited[maxNM], cnt[maxNM];
char grid[maxNM];
vector<int> adj[maxNM], adj_rev[maxNM];
int ans = 0, ans2 = 0;

void dfs2(int curNode, int dist, int len){
	if(c[curNode] == 1){
		cnt[dist%len]++;
	}
	
	visited[curNode] = 2;
	for(auto nxt : adj_rev[curNode]){
		if(visited[nxt] != 2){
			dfs2(nxt, dist+1, len);
		}
	}
}

void dfs(int curNode, int prvNode){	
	if(visited[curNode] == 1){
		int node = prvNode, length = 1, cur = 0;
		
		while(node != curNode){
			length++;
			node = parrent[node];
		}
		
		ans += length;
		fill(cnt, cnt+length, 0);
		
		dfs2(node, 0, length);
		
		for(int x=0;x<length;x++){
			ans2 += min(1, cnt[x]);
		}
		return;
	}
	
	visited[curNode] = 1;
	
	for(auto nxt : adj[curNode]){
		if(visited[nxt] != 2){
			parrent[nxt] = curNode;
			dfs(nxt, curNode);
		}
	}
	
	visited[curNode] = 2;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				char tmp;
				cin >> tmp;
				
				c[x*m+y] = (tmp == '0');
				adj[x*m+y].clear();
				adj_rev[x*m+y].clear();
			}
		}
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				cin >> grid[x*m+y];
				
				int newX = x, newY = y;
				if(grid[x*m+y] == 'U'){
					newX--;
				} else if(grid[x*m+y] == 'D'){
					newX++;
				} else if(grid[x*m+y] == 'L'){
					newY--;
				} else if(grid[x*m+y] == 'R'){
					newY++;
				}
				
				adj[x*m+y].push_back(newX*m+newY);
				adj_rev[newX*m+newY].push_back(x*m+y);
			}
		}
		
		fill(visited, visited+n*m, 0);
		
		ans = 0; ans2 = 0;
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(!visited[x*m+y]){
					dfs(x*m+y, x*m+y);
				}
			}
		}
		
		cout << ans << " " << ans2 << "\n";
	}

    return 0;
}


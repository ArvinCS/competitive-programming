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

const int maxN = 2005;
const int maxK = 3e5 + 5;

vector<pair<int, int>> v;
set<int> adj[maxK];
pair<int, int> ans[maxK];
int adjDist[maxK];
bool grid[maxN][maxN];
vector<int> comp[maxN][maxN];
int dist[maxN][maxN];

pair<int, int> dfs(int curNode, int prvNode){
	if(ans[curNode].first != inf_int) return ans[curNode];
		
	pair<int, int> p;
	if(adj[curNode].size() != 1){
		p = v[curNode];
	} else {
		int nxt = *(adj[curNode].begin());
		if(nxt == prvNode){
			p = v[prvNode];
		} else {
			p = dfs(nxt, curNode);
			if(p == v[curNode]){
				p = v[nxt];
			}
		}
	}
	return ans[curNode] = p;
}

int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	char c;
	for(int x=0;x<8;x++){
		cin >> c;
	}
	
	int n, m, k, t;
	cin >> n >> m >> k >> t;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			char c;
			cin >> c;
			
			grid[x][y] = (c == 'X');
			if(grid[x][y]){
				v.push_back({x, y});			
			}
		}
	}
	
	fill(dist[0], dist[n], inf_int);
	fill(adjDist, adjDist+k, inf_int);
	fill(ans, ans+k, make_pair(inf_int, inf_int));
	
	queue<pair<int, int>> q;
	for(int x=0;x<k;x++){
		q.push(make_pair(v[x].first, v[x].second));
		dist[v[x].first][v[x].second] = 0;
		comp[v[x].first][v[x].second].push_back(x);
	}
	
	while(!q.empty()){
		int a = q.front().first, b = q.front().second;
		q.pop();
				
		for(int y=0;y<4;y++){
			int c = a+moveX[y], d = b+moveY[y];
			if(c >= 0 && c < n && d >= 0 && d < m){
				if(comp[c][d].size() > 0){
					for(auto cur : comp[a][b]){
						if(adj[cur].size() == 2) continue;
						
						for(auto nxt : comp[c][d]){
							if(nxt == cur) continue;
							
							if(adj[cur].size() == 0 || adjDist[cur] >= dist[a][b]+dist[c][d]+1){
								if(adjDist[cur] > dist[a][b]+dist[c][d]+1){
									adj[cur].clear();
								}
								
								adj[cur].insert(nxt);
								adjDist[cur] = dist[a][b]+dist[c][d]+1;
							}
						}
					}
				}
				
				if(dist[c][d] == dist[a][b]+1){
					for(auto cur : comp[a][b]){	
						if(comp[c][d].size() > 2) break;
											
						bool contain = false;
						for(auto nxt : comp[c][d]){
							if(nxt == cur){
								contain = true;
								break;
							}
						}
						
						if(!contain) comp[c][d].push_back(cur);	
					}
				} else if(dist[c][d] > dist[a][b]+1){
					dist[c][d] = dist[a][b]+1;
					comp[c][d] = comp[a][b];
					
					q.push(make_pair(c, d));
				}
			}
		}		
	}
	
	for(int x=0;x<k;x++){
		dfs(x, x);
	}
	
	for(int x=0;x<t;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		
		if(comp[a][b].size() == 1){
			cout << ans[comp[a][b][0]].first+1 << " " << ans[comp[a][b][0]].second+1 << "\n";
		} else {
			cout << a+1 << " " << b+1 << "\n";
		}
	}
	
//	for(int x=0;x<n;x++){
//		for(int y=0;y<m;y++){
//			cout << dist[x][y].first << "||" << dist[x][y].second.size() << " ";
//		}
//		cout << "\n";
//	}
    return 0;
}


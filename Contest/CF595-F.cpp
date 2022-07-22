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

const int maxN = 205;

vector<int> adj[maxN], v[maxN];
int a[maxN], table[maxN], dist[maxN];
map<int, int> mp[maxN];
int n, k;

int dfs(int curNode, int prvNode){
	int ans = 0;
	mp[curNode][0] = a[curNode];
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){		
			ans = max(ans, dfs(nxt, curNode));
			
			int tmp[n+1];
			fill(tmp, tmp+n+1, 0);
			
			for(int x=0;x<=n;x++){
				for(int y=max(0, k-x);y<=n;y++){
					tmp[min(x, y+1)] = max(tmp[min(x, y+1)], mp[curNode][x]+mp[nxt][y]);
				}
				tmp[x+1] = max(tmp[x+1], mp[nxt][x]);
			}
			for(int x=n;x>=0;x--){
				mp[curNode][x] = max(mp[curNode][x], tmp[x]);
				mp[curNode][x] = max(mp[curNode][x], mp[curNode][x+1]);
			}
		}
	}
	
	return max(ans, mp[curNode][0]);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> n >> k;
	
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	for(int x=0;x<n-1;x++){
		int u, v;
		cin >> u >> v;
		
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	cout << dfs(0, 0) << "\n";
    return 0;
}


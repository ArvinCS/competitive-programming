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

bool visited[maxN];
int v[maxN], w[maxN], color[maxN];
vector<int> adj[maxN];

bool dfs(int curNode, int cur){
	visited[curNode] = true;
	color[curNode] = cur;
	
	bool valid = true;
	for(auto nxt : adj[curNode]){
		if(!visited[nxt]){
			valid &= dfs(nxt, cur^1);
		} else {
			if(color[curNode] == color[nxt]){
				valid = false;
			}
		}
	}
	return valid;
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
		int n, m;
		cin >> n >> m;
		
		for(int x=0;x<n;x++){
			cin >> v[x];
		}
		for(int x=0;x<n;x++){
			cin >> w[x];
		}
		
		for(int x=0;x<n;x++){
			adj[x].clear();
			visited[x] = false;
			color[x] = -1;
		}
		for(int x=0;x<m;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		bool cycle = !dfs(0, 0);
		
		ll sum[2];
		fill(sum, sum+2, 0);
		
		for(int x=0;x<n;x++){
			sum[color[x]] += (v[x]-w[x]);
		}
		
		bool possible = false;
		if(sum[0] == sum[1]){
			possible |= true;
		}
		
		if(cycle && (abs(sum[0]-sum[1])%2 == 0)){
			possible |= true;
		}
		
		if(possible) cout << "YES\n";
		else cout << "NO\n";
	}

    return 0;
}


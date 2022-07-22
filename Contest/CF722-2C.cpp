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

const int maxN = 1e5 + 5;

ll data[2][maxN];
ll table[2][maxN];

ll dfs(int curNode, int prvNode, bool right, vector<int> adj[]){
	if(table[right][curNode] != -1) return table[right][curNode];
	
	ll ans = 0;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			ll tmp1 = abs(data[right][curNode]-data[!right][nxt])+dfs(nxt, curNode, !right, adj);
			ll tmp2 = abs(data[right][curNode]-data[right][nxt])+dfs(nxt, curNode, right, adj);
			
			ans += max(tmp1, tmp2);
		}
	}
	return table[right][curNode] = ans;
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
		int n;
		cin >> n;
		
		fill(table[0], table[2], -1);
		
		vector<int> adj[n];
		for(int x=0;x<n;x++){
			cin >> data[0][x] >> data[1][x];
		}
		for(int x=0;x<n-1;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
				
		
		cout << max(dfs(0, -1, false, adj), dfs(0, -1, true, adj)) << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar


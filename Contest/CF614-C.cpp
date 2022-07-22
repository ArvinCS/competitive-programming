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

const int maxN = 3e3 + 5;

vector<pair<int, int>> adj[maxN];
int sz[maxN][maxN], parrent[maxN][maxN];
ll table[maxN][maxN];
int root = 0;

int dfs(int curNode, int prvNode){
	sz[root][curNode] = 1;
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			parrent[root][nxt.first] = curNode;
			sz[root][curNode] += dfs(nxt.first, curNode);
		}
	}
	return sz[root][curNode];
}

ll dp(int left, int right){
	if(left == right) return 0;
	if(table[left][right] != -1) return table[left][right];
	
	ll ans = sz[right][left] * 1ll * sz[left][right] + max(dp(parrent[right][left], right), dp(left, parrent[left][right]));
	return table[left][right] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	pair<int, int> edge[n];
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		edge[x] = {a, b};
		adj[a].push_back({b, x});
		adj[b].push_back({a, x});
	}
	
	for(int x=0;x<n;x++){
		root = x;
		dfs(x, x);
	}
	
	fill(table[0], table[maxN], -1);
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			ans = max(ans, dp(x, y));
		}
	}
	
	cout << ans << "\n";
    return 0;
}


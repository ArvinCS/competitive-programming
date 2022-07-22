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

vector<pair<int, ll>> adj[maxN];
vector<tuple<int, int, ll>> edge;
int sz[maxN], level[maxN];

ll dfs(int curNode, int prvNode){
	sz[curNode] = 1;
	
	ll ans = 0;
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			level[nxt.first] = level[curNode]+1;
			ans += dfs(nxt.first, curNode);
			
			if(sz[nxt.first]&1) ans += nxt.second;
			sz[curNode] += sz[nxt.first];
		}
	}
	return ans;
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
		int n;
		cin >> n;
		
		for(int x=0;x<2*n;x++){
			adj[x].clear();
		}
		edge.clear();
		
		for(int x=0;x<2*n-1;x++){
			int a, b, t;
			cin >> a >> b >> t;
			
			a--; b--;
			adj[a].push_back({b, t});
			adj[b].push_back({a, t});
			edge.push_back(make_tuple(a, b, t));
		}
		
		level[0] = 0;
		ll mn = dfs(0, 0), mx = 0;
		
		for(auto t : edge){
			if(level[get<0>(t)] > level[get<1>(t)]) swap(get<0>(t), get<1>(t));
			
			mx += get<2>(t) * min((2*n-sz[get<1>(t)]), sz[get<1>(t)]);
		}
		
		cout << mn << " " << mx << "\n";
	}
	
    return 0;
}


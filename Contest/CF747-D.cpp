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

vector<pair<int, int>> adj[maxN];
int color[maxN], comp[maxN], cnt[maxN];
bool visited[maxN];

bool dfs(int curNode){
	visited[curNode] = true;
	comp[curNode] = 1;
	cnt[curNode] = 1;
	
	bool possible = true;
	for(auto nxt : adj[curNode]){
		if(!visited[nxt.first]){
			color[nxt.first] = (color[curNode]^nxt.second);
			possible &= dfs(nxt.first);
			
			comp[curNode] += comp[nxt.first];
			if(color[nxt.first] == color[curNode]){
				cnt[curNode] += cnt[nxt.first];
			} else {
				cnt[curNode] += comp[nxt.first] - cnt[nxt.first];
			}
		}
		
		if(color[nxt.first] != (nxt.second^color[curNode])){
			possible = false;
		}
	}
	
	return possible;
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
			adj[x].clear();
			visited[x] = false;
		}
		
		for(int x=0;x<m;x++){
			int a, b;
			string c;
			
			cin >> a >> b >> c;
			
			a--; b--;
			adj[a].push_back({b, (c == "imposter")});
			adj[b].push_back({a, (c == "imposter")});
		}
		
		bool possible = true;
		int ans = 0;
		for(int x=0;x<n;x++){
			if(!visited[x]){
				color[x] = 1;
				possible &= dfs(x);
				
				ans += max(cnt[x], comp[x]-cnt[x]);
			}
		}
		
		if(possible){
			cout << ans << "\n";
		} else {
			cout << "-1\n";
		}
	}
	
    return 0;
}


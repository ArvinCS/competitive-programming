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

const int maxN = 3e5 + 5;

int inTime[maxN], outTime[maxN], t = 0;

void dfs(int curNode, vector<int> adj[]){
	inTime[curNode] = t++;
	
	for(auto nxt : adj[curNode]){
		dfs(nxt, adj);
	}
	
	outTime[curNode] = t++;
}

int dfs2(int curNode, vector<int> adj[], set<pair<int, int>> v){
	v.insert({outTime[curNode], inTime[curNode]});
	
	if(adj[curNode].size() == 0){
		int ans = 0, cur = 0;
		
		for(auto p : v){
			if(p.second > cur){
				cur = p.first;
				ans++;
			}
		}
		
		return ans;
	}
		
	int ans = 0;
	for(auto nxt : adj[curNode]){
		ans = max(ans, dfs2(nxt, adj, v));
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
		
		vector<int> adj[n], adj2[n];
		for(int x=1;x<n;x++){
			int p;
			cin >> p;
			
			adj[p-1].push_back(x);
		}
		for(int x=1;x<n;x++){
			int p;
			cin >> p;
			
			adj2[p-1].push_back(x);
		}
		
		dfs(0, adj2);
		
		set<pair<int, int>> v;
		int ans = dfs2(0, adj, v);
		
		cout << ans << "\n";
	}
    return 0;
}

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

tuple<int, int, ll> edges[maxN];
ll cnt[maxN];

ll dfs(int curNode, int prvNode, ll cost, vector<pair<int, int>> adj[]){
	if(curNode != 1 && adj[curNode].size() == 1){
		return cost;
	}
	
	ll tmp = 0;
	for(auto p : adj[curNode]){
		if(prvNode != p.first){
			tmp += dfs(p.first, curNode, cost+get<2>(edges[p.second]), adj);
		}
	}
	return tmp;
}

int dfs2(int curNode, int prvNode, vector<pair<int, int>> adj[]){
	if(curNode != 1 && adj[curNode].size() == 1){
		return 1;
	}
	
	int sum = 0;
	for(auto p : adj[curNode]){
		if(p.first != prvNode){
			int tmp = dfs2(p.first, curNode, adj);
			sum += tmp;
			cnt[p.second] += tmp;
		}
	}
	return sum;
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
		ll m;
		cin >> n >> m;
		
		fill(cnt, cnt+n, 0);
		
		vector<pair<int, int>> adj[n+1];
		for(int x=0;x<n-1;x++){
			int a, b;
			ll w;
			cin >> a >> b >> w;
			
			adj[a].push_back({b, x});
			adj[b].push_back({a, x});
			edges[x] = make_tuple(a, b, w);
		}
		
		ll cost = dfs(1, 0, 0, adj);
		dfs2(1, 0, adj);
		
		priority_queue<pair<ll, int>> pq;
		for(int x=0;x<n-1;x++){
			pq.push({cnt[x]*(get<2>(edges[x])-get<2>(edges[x])/2), x});
		}
		
		ll ans = 0;
		while(cost > m && !pq.empty()){
			pair<ll, int> p = pq.top();
			pq.pop();
			
//			cout << cost << " " << p.first << " " << p.second << "\n";
			cost -= p.first;
			get<2>(edges[p.second]) /= 2;
			ans++;
			if(get<2>(edges[p.second]) > 0) pq.push({cnt[p.second]*(get<2>(edges[p.second])-get<2>(edges[p.second])/2), p.second});
		}
		cout << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar


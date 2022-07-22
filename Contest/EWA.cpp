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

vector<int> adj[maxN];

vector<int> bfs(int n, int curNode){	
	int dist[n];
	fill(dist, dist+n, -1);
	
	queue<int> q;
	q.push(curNode);
	
	dist[curNode] = 0;
	
	while(!q.empty()){
		int node = q.front();
		q.pop();
		
		for(auto v : adj[node]){
			if(dist[v] != -1) continue;
			dist[v] = dist[node] + 1;
			q.push(v);
		}
	}
	
	vector<int> odd;
	for(int x=0;x<n;x++){
		if(adj[x].size() == 1){
			if(dist[x]&1) odd.push_back(x);
		}
	}
	
	return odd;	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int ans1 = 1, ans2 = n-1;
	for(int x=0;x<n;x++){
		if(adj[x].size() == 1){
			vector<int> v = bfs(n, x);
			if(v.size() > 0){
				ans1 = 3;
			}
			break;
		}
	}
	
	unordered_set<int> st;
	for(int x=0;x<n;x++){
		if(adj[x].size() == 1){
			if(st.count(adj[x][0])){
				ans2--;
			}
			st.insert(adj[x][0]);
		}
	}
	
	cout << ans1 << " " << ans2 << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar


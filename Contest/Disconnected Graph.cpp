#include <iostream>
#include <vector>

using namespace std;

bool visited[50001], special[50001];

unsigned long long dfs(int node, vector<int> adj[]){ // return sum of special nodes
	unsigned long long ans = 0;
	for(unsigned long long x=0;x<adj[node].size();x++){
		if(!visited[adj[node][x]]){
			//cout << node << " -> " << adj[node][x] << "\n";
			visited[adj[node][x]] = true;
			if(special[adj[node][x]]){
				ans++;
			}
			ans += dfs(adj[node][x], adj);
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short t;
	cin >> t;
	while(t--){
		fill(begin(visited), end(visited), false);
		fill(begin(special), end(special), false);
		int n, e, r;
		unsigned long long q;
		cin >> n >> e >> q >> r;
		
		vector<pair<int, int>> edges;
		vector<int> specialVec, adj[n+1] = {};
		
		bool deleted[e+1];
		fill(deleted, deleted+e+1, false);
		int tmp, tmp2;
		
		for(int x=0;x<e;x++){
			cin >> tmp >> tmp2;
			edges.push_back({tmp, tmp2});
		}
		
		for(int x=0;x<q;x++){
			cin >> tmp;
			special[tmp] = true;
			specialVec.push_back(tmp);
		}
		
		for(int x=0;x<r;x++){
			cin >> tmp;
			deleted[tmp] = true;
		}

		for(int x=0;x<e;x++){
			if(deleted[x+1]) continue;
			int a = edges[x].first, b = edges[x].second;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		unsigned long long connected = 0;
		for(int x=0;x<specialVec.size();x++){
			if(!visited[specialVec[x]]){
				visited[specialVec[x]] = true;
				unsigned long long cnt = 1 + dfs(specialVec[x], adj);
			
				connected += cnt*(cnt-1)/2;
			}
		}
		
		unsigned long long ans = (q*(q-1)/2) - connected;
		cout << ans << "\n";
	}
	
    return 0;
}

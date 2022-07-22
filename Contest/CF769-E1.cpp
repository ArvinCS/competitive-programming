#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 6e3 + 5;
const int logN = log2(maxN)+1;

vector<int> adj[maxN];
int dist[maxN], parent[logN][maxN];

int findLCA(int x, int y){
	if(dist[x] > dist[y]) swap(x, y);
	
	for(int i=logN-1;i>=0;i--){
		if(dist[x] <= dist[y]-(1 << i)){
			y = parent[i][y];
		}
	}
	
	if(x == y) return x;
	
	for(int i=logN-1;i>=0;i--){
		if(parent[i][x] != parent[i][y]){
			x = parent[i][x];
			y = parent[i][y];
		}
	}
	return parent[0][x];
}

int findDist(int x, int y){
	return dist[x]+dist[y]-2*dist[findLCA(x,y)];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		for(int x=0;x<=n;x++){
			adj[x].clear();
		}
		for(int x=0;x<n-1;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		fill(dist, dist+n, -1);
				
		dist[0] = parent[0][0] = 0;
		vector<int> q;
		q.push_back(0);
		
		for(int x=0;x<q.size();x++){
			for(auto nxt : adj[q[x]]){
				if(dist[nxt] == -1){
					dist[nxt] = dist[q[x]]+1;
					parent[0][nxt] = q[x];
					q.push_back(nxt);
				}
			}
		}
		for(int x=1;x<logN;x++){
			for(int y=0;y<n;y++){
				parent[x][y] = parent[x-1][parent[x-1][y]];
			}
		}
		
		int ans[n+1];
		fill(ans, ans+n+1, dist[q.back()]);
		
		int node1 = q.back(), node2 = q.back(), d = 0;
		for(int x=q.size()-1;x>=1;x--){
			int curNode = q[x];
			int d1 = findDist(node1, curNode);
			int d2 = findDist(node2, curNode);
			
			if(max(d1, d2) > d){
				if(d1 > d2){
					node2 = curNode;
					d = d1;
				} else {
					node1 = curNode;
					d = d2;
				}
			}
			
			int bound = dist[q[x-1]];
			int mid = (d+1)/2;
			
			int mx = bound-mid;
			if(mx > 0){
				ans[mx] = min(ans[mx], bound);
			}
		}
		
		for(int x=n-1;x>=0;x--){
			ans[x] = min(ans[x], ans[x+1]);
		}
		
		for(int x=1;x<=n;x++){
			if(x > 1) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3e5 + 5;

vector<int> adj[maxN], pending;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		
		if(a == -1){
			pending.push_back(b);
			continue;
		}
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	auto bfs = [&](int startNode, int dist[]) -> void {
		fill(dist, dist+n, 1e9);
		
		queue<int> q;
		dist[startNode] = 0;
		q.push(startNode);
		
		while(!q.empty()){
			int curNode = q.front();
			q.pop();
			
			for(auto nxt : adj[curNode]){
				if(dist[nxt] > dist[curNode]+1){
					dist[nxt] = dist[curNode]+1;
					q.push(nxt);
				}
			}
		}
	};
	
	int dist1[n], dist2[n];
	bfs(0, dist1);
	bfs(n-1, dist2);
	
	int ans = 1e9;
	if(dist1[n-1] != 1e9){
		ans = dist1[n-1];
	}
		
	int mn = 1e9, mn2 = 1e9;
	for(int x=0;x<pending.size();x++){
		if(dist2[pending[x]] != 1e9){
			ans = min(ans, mn+dist2[pending[x]]+2);			
		}
		
		mn = min(mn, dist1[pending[x]]);
	}
	
	int sz = pending.size();
	mn = 1e9;
	for(int x=sz-1;x>=0;x--){
		if(dist2[pending[x]] != 1e9){
			ans = min(ans, mn+dist2[pending[x]]+2);			
		}
		
		mn = min(mn, dist1[pending[x]]);
		mn2 = min(mn2, dist2[pending[x]]);
	}
	
	for(int x=0;x<n;x++){
		int tmp = ans;
		
		if(mn != 1e9 && dist2[x] != 1e9) ans = min(ans, mn+dist2[x]+1);
		if(mn2 != 1e9 && dist1[x] != 1e9) ans = min(ans, mn2+dist1[x]+1);
		
		if(x > 0) cout << " ";
		cout << (ans < 1e9 ? ans : -1);
		ans = tmp;
	}
	cout << "\n";
    return 0;
}


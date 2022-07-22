#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 5e5 + 5;

vector<pair<int, int>> adj[maxN];
vector<pair<int, int>> rev_adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		int u, v, t;
		cin >> u >> v >> t;
		
		u--; v--;
		adj[u].push_back({v, t});
		rev_adj[v].push_back({u, t});
	}
	
	int dist[n][2];
	fill(dist[0], dist[n], 1e9);
	
	queue<int> q;
	dist[n-1][0] = dist[n-1][1] = 0;
	q.push(n-1);
	
	while(!q.empty()){
		int curNode = q.front();
		q.pop();
		
		for(auto nxt : rev_adj[curNode]){
			if(dist[nxt.first][nxt.second] > max(dist[curNode][0], dist[curNode][1])+1){
				dist[nxt.first][nxt.second] = max(dist[curNode][0], dist[curNode][1])+1;
				q.push(nxt.first);
			}
		}
	}
	
	for(int x=0;x<n;x++){
		if(dist[x][0] == 1e9 && dist[x][1] == 1e9){
			q.push(x);
		}
	}
	
	while(!q.empty()){
		int curNode = q.front();
		q.pop();
		
		for(auto nxt : rev_adj[curNode]){
			if(dist[nxt.first][nxt.second] > max(dist[curNode][0], dist[curNode][1])+1){
				dist[nxt.first][nxt.second] = max(dist[curNode][0], dist[curNode][1])+1;
				q.push(nxt.first);
			}
		}
	}
	
	int mx = max(dist[0][0], dist[0][1]);
	cout << (mx != 1e9 ? mx : -1) << "\n";
	for(int x=0;x<n;x++){
		cout << (dist[x][0] >= dist[x][1] ? '0' : '1');
	}
	cout << "\n";
    return 0;
}


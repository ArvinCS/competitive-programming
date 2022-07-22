#include <bits/stdc++.h>

using namespace std;

const int maxN = 3e5 + 5;

vector<int> adj[maxN];
int dist[maxN][2];
bool visited[maxN];

struct DSU {
	int parrent[maxN], sz[maxN], d[maxN];
	
	void reset(){
		for(int x=0;x<maxN;x++){
			parrent[x] = x;
			sz[x] = 1;
			d[x] = 0;
		}
	}
	
	int getParrent(int x){
		if(parrent[x] == x) return x;
		return parrent[x] = getParrent(parrent[x]);
	}	
	
	void merge(int x, int y){
		int a = getParrent(x);
		int b = getParrent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parrent[b] = a;
			sz[a] += sz[b];
			d[a] = max(d[a], max(d[b], (d[a]+1)/2 + (d[b]+1)/2 + 1));
		}
	}
};

DSU dsu;

int bfs(int source, int id){
	queue<int> q;
	dist[source][id] = 0;
	q.push(source);
	
	vector<int> v;
	while(!q.empty()){
		int curNode = q.front();
		q.pop();
		
		v.push_back(curNode);
		for(auto nxt : adj[curNode]){
			if(dist[nxt][id] > dist[curNode][id]+1){
				dist[nxt][id] = dist[curNode][id]+1;
				q.push(nxt);
			}
		}
	}
	
	int mx = source;
	for(int x=0;x<v.size();x++){
		dsu.merge(source, v[x]);
		visited[v[x]] = true;
		
		if(dist[mx][id] < dist[v[x]][id]){
			mx = v[x];
		}
	}
	return mx;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n, m, q;
	cin >> n >> m >> q;
	
	dsu.reset();
		
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	fill(visited, visited+n, false);
	fill(dist[0], dist[n], 1e9);
	
	for(int x=0;x<n;x++){
		if(!visited[x]){
			int far = bfs(x, 0);
			int diameter = dist[bfs(far, 1)][1];
			
			dsu.d[dsu.getParrent(x)] = diameter;
		}
	}
	
	while(q--){
		int t;
		cin >> t;
		
		if(t == 1){
			int a;
			cin >> a;
			
			a--;
			cout << dsu.d[dsu.getParrent(a)] << "\n";
		} else {
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			dsu.merge(a, b);
//			cout << dsu.d[dsu.getParrent(a)] << "\n";
		}
	}
	
    return 0;
}


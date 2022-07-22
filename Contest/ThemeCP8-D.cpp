#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxNM = 1e5;

struct DSU {
	int parent[maxNM], sz[maxNM];
	
	void reset(){
		for(int x=0;x<maxNM;x++){
			parent[x] = x;
			sz[x] = 1;
		}
	}
	
	int getParent(int x){
		if(parent[x] == x) return x;
		return parent[x] = getParent(parent[x]);
	}
	
	void merge(int x, int y){
		int a = getParent(x);
		int b = getParent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parent[b] = a;
			sz[a] += sz[b];
		}
	}
	
	bool check(int x, int y){
		return getParent(x) == getParent(y);
	}
};

DSU dsu;
vector<int> adj[maxNM];
bool visited[maxNM];
int ans[maxNM];

void dfs(int curNode, vector<int> &v){
	visited[curNode] = true;
	
	for(auto nxt : adj[curNode]){
		if(!visited[nxt]){
			dfs(nxt, v);
		}
	}
	
	v.push_back(curNode);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	dsu.reset();
	
	int a[n], b[m];
	fill(a, a+n, -1);
	fill(b, b+m, -1);
	
	string s[n];
	
	int cnt = 0;
	for(int x=0;x<n;x++){
		cin >> s[x];
		
		vector<int> w;
		for(int y=0;y<m;y++){
			if(s[x][y] == '='){
				dsu.merge(x, n+y);
			}	
		}
	}
	
	int idx[n+m];
	for(int x=0;x<n+m;x++){
		if(dsu.getParent(x) == x){
			idx[x] = cnt++;
		}
	}
	for(int x=0;x<n;x++){
		a[x] = idx[dsu.getParent(x)];
	}
	for(int x=0;x<m;x++){
		b[x] = idx[dsu.getParent(n+x)];
	}
	
	set<pair<int, int>> st;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(s[x][y] == '<'){
				adj[b[y]].push_back(a[x]);
				st.insert({a[x], b[y]});
				st.insert({b[y], a[x]});
			} else if(s[x][y] == '>'){
				adj[a[x]].push_back(b[y]);
				st.insert({a[x], b[y]});
				st.insert({b[y], a[x]});
			}
		}
	}
	
	fill(visited, visited+cnt, false);
	
	vector<int> topo;
	for(int x=0;x<cnt;x++){
		if(!visited[x]){
			dfs(x, topo);
		}
	}
	
	cnt = 1;
	for(int x=0;x<topo.size();x++){
		if(x > 0 && st.count({topo[x-1], topo[x]})) cnt++;
		ans[topo[x]] = cnt;
	}
	
	bool possible = true;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(s[x][y] == '<'){
				if(ans[a[x]] >= ans[b[y]]){
					possible = false;
				}
			} else if(s[x][y] == '>'){
				if(ans[a[x]] <= ans[b[y]]){
					possible = false;
				}
			} else {
				if(ans[a[x]] != ans[b[y]]){
					possible = false;
				}
			}
		}
	}
	
	if(possible){
		cout << "Yes\n";
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[a[x]];
		}
		cout << "\n";
		for(int x=0;x<m;x++){
			if(x > 0) cout << " ";
			cout << ans[b[x]];
		}
		cout << "\n";
	} else {
		cout << "No\n";
	}
    return 0;
}


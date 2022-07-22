#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxA = 2e5 + 5;

struct DSU {
	int parent[4*maxA], sz[4*maxA];
	
	void reset(){
		for(int x=0;x<4*maxA;x++){
			parent[x] = x;
			sz[x] = 1;
		}
	}
	
	int getParent(int x){
		if(parent[x] == x) return x;
		return parent[x] = getParent(parent[x]);
	}
	
	bool merge(int x, int y){
		int a = getParent(x), b = getParent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parent[b] = a;
			sz[a] += sz[b];
			return true;
		}
		return false;
	}
} dsu;

vector<pair<int, int>> adj[2][maxA];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	array<ll, 3> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x][0] >> p[x][1];
		p[x][2] = x;
	}
	
	sort(p, p+n);
	
	// case 1: go east/west, WLOG east
	// all points with x < x0 contribute +0
	// all points with y > y0:
	// +1 iff (y-y0) == (x-x0) -> y = x-x0+y0 -> y-x = -x0-y0
	//
	// all points with y == y0:
	// +1 iff -t + x == t + x0 -> 2t == x-x0 -> t = (x-x0)/2
	// if t can be real number then always +1
	// 
	// case 2: go north/south, WLOG north
	// all points with y < y0 contribute +0
	// all points with x > x0:
	// +1 iff (x-x0) == (y-y0) -> x = y-y0+x0 -> x-y = -y0+x0 -> y-x = y0-x0
	
	int s = -1;
	for(int x=0;x<n;x++){
		if(p[x][2] == 0){
			s = x;
			break;
		}
	}
	
	vector<ll> v[2];
	for(int x=0;x<n;x++){
		v[0].push_back(p[x][1]-p[x][0]);
		v[1].push_back(p[x][1]-(p[n-1][0]-p[x][0]));
	}
	
	for(int x=0;x<2;x++){
		sort(v[x].begin(), v[x].end());
		v[x].erase(unique(v[x].begin(), v[x].end()), v[x].end());
	}
	
	int idx[n][2];
	for(int x=0;x<n;x++){		
		idx[x][0] = lower_bound(v[0].begin(), v[0].end(), p[x][1]-p[x][0]) - v[0].begin();
		if(x != s) adj[0][idx[x][0]].push_back({p[x][0], x});
		
		idx[x][1] = lower_bound(v[1].begin(), v[1].end(), p[x][1]-(p[n-1][0]-p[x][0])) - v[1].begin();
		if(x != s) adj[1][idx[x][1]].push_back({p[x][0], x});
		
		cout << idx[x][0] << " " << 500 + idx[x][1] << "\n";
	}
	
	dsu.reset();
	
	queue<array<int, 2>> q;
	q.push({idx[s][0], 0});
	q.push({idx[s][1], 1});
	
	while(!q.empty()){
		array<int, 2> cur = q.front();
		q.pop();
		
		cout << " -> " << cur[0] << " " << cur[1] << "\n";
		for(auto nxt : adj[cur[1]][cur[0]]){
			if(dsu.merge(cur[0] + (cur[1] ? maxA : 0), idx[nxt.second][cur[1]^1] + ((cur[1]^1) ? maxA : 0))){
				q.push({idx[nxt.second][cur[1]^1], cur[1]^1});
			}
		}
	}
	
	if(dsu.getParent(idx[s][0]) != dsu.getParent(idx[s][1] + maxA)){
		cout << dsu.sz[dsu.getParent(idx[s][0])] + dsu.sz[dsu.getParent(idx[s][1] + maxA)] - 1 << "\n";
		cout << dsu.sz[dsu.getParent(idx[s][0])] << " " << dsu.sz[dsu.getParent(idx[s][1] + maxA)] << "\n";
	} else {
		cout << dsu.sz[dsu.getParent(idx[s][0])] - 1 << "\n";
	}
    return 0;
}


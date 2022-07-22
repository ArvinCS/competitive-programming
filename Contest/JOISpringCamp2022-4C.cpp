#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
const int maxN = 505;
 
struct DSU {
	int parent[maxN], sz[maxN];
	
	void reset(){
		for(int x=0;x<maxN;x++){
			parent[x] = x;
			sz[x] = 1;
		}
	}
	
	int getParent(int x){
		if(parent[x] == x) return x;
		return parent[x] = getParent(parent[x]);
	}
	
	bool merge(int x, int y){
		int a = getParent(x);
		int b = getParent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parent[b] = a;
			sz[a] += sz[b];
			return true;
		}
		return false;
	}
	
	bool check(int x, int y){
		return getParent(x) == getParent(y);
	}
};
 
DSU dsu;
 
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<array<int, 3>> edge;
	for(int x=0;x<m;x++){
		int a, b, w;
		cin >> a >> b >> w;
		
		a--; b--;
		edge.push_back({w, a, b});
	}
	
	sort(edge.begin(), edge.end());
	
	vector<array<int, 3>> v;
	for(int x=0;x<m;x++){
		dsu.reset();
		
		int l = x-1;
		while(l >= 0){
			dsu.merge(edge[l][1], edge[l][2]);
			if(dsu.check(edge[x][1], edge[x][2])) break;
			l--;
		}
		
		dsu.reset();
		
		int r = x+1;
		while(r < m){
			dsu.merge(edge[r][1], edge[r][2]);
			if(dsu.check(edge[x][1], edge[x][2])) break;
			r++;
		}
		
		int valL = (l >= 0 ? (edge[l][0]+edge[x][0]+1)/2 : -1);
		int valR = (r < m ? (edge[x][0]+edge[r][0]+1)/2 : 1e9 + 1);
		
		v.push_back({valL, -1, edge[x][0]});
		v.push_back({edge[x][0], 2, -2 * edge[x][0]});
		v.push_back({valR, -1, edge[x][0]});
	}
	
	sort(v.begin(), v.end());
	
	int q;
	cin >> q;
	
	int pos = 0;
	ll mul = 0, val = 0;
	while(q--){
		ll cur;
		cin >> cur;
		
		while(pos < v.size() && v[pos][0] <= cur){
			mul += v[pos][1];
			val += v[pos][2];
			pos++;
		}
		
		cout << mul*cur + val << "\n";
	}
    return 0;
}

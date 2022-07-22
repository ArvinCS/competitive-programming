#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

struct DSU {
	int parrent[maxN], sz[maxN];
	
	void reset(){
		for(int x=0;x<maxN;x++){
			parrent[x] = x;
			sz[x] = 1;
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
		}
	}
};

vector<tuple<int, int, int>> edges;
DSU dsu;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, q;
	cin >> n >> m >> q;	
	
	vector<tuple<int, int, int>> v;
	for(int x=0;x<m;x++){
		int a, b, c;
		cin >> a >> b >> c;
		
		a--; b--;
		edges.push_back(make_tuple(c, a, b));
		v.push_back(make_tuple(c, 1, x));
	}
	
	int l[q], r[q];
	for(int x=0;x<q;x++){
		int c;
		cin >> l[x] >> r[x] >> c;
		
		l[x]--; r[x]--;
		v.push_back(make_tuple(c, 2, x));
	}
	
	dsu.reset();
	sort(v.begin(), v.end());
	
	bool ans[q];
	for(auto t : v){
		if(get<1>(t) == 1){
			dsu.merge(get<1>(edges[get<2>(t)]), get<2>(edges[get<2>(t)]));
		} else {
			if(dsu.getParrent(l[get<2>(t)]) != dsu.getParrent(r[get<2>(t)])){
				ans[get<2>(t)] = true;
			} else {
				ans[get<2>(t)] = false;
			}
		}
	}
	
	for(int x=0;x<q;x++){
		if(ans[x]){
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
    return 0;
}


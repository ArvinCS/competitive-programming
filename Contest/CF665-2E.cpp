#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e6 + 5;

struct Fenwick {
	int tree[maxN];
	
	void reset(){
		fill(tree, tree+maxN, 0);
	}
	
	int query(int pos){
		pos++;
		
		int ans = 0;
		while(pos > 0){
			ans += tree[pos];
			pos -= pos&(-pos);
		}
		return ans;
	}
	
	void update(int pos, int val){
		pos++;
		
		while(pos < maxN){
			tree[pos] += val;
			pos += pos&(-pos);
		}
	}
};

Fenwick tree;
vector<int> w[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	array<int, 3> h[n], v[m];
	for(int x=0;x<n;x++){
		for(int y=0;y<3;y++){
			cin >> h[x][y];
		}
	}
	for(int x=0;x<m;x++){
		for(int y=0;y<3;y++){
			cin >> v[x][y];
		}
	}
	
	vector<pair<int, int>> z;
	
	ll ans = 1;
	for(int x=0;x<n;x++){
		if(h[x][1] == 0 && h[x][2] == 1e6) ans++;
		w[h[x][1]].push_back(x);
		w[h[x][2]+1].push_back(x);
	}
	for(int x=0;x<m;x++){
		if(v[x][1] == 0 && v[x][2] == 1e6) ans++;
		z.push_back({v[x][0], x});
	}
	
	if(!z.empty()) sort(z.begin(), z.end());
	tree.reset();
	
	int pos = 0;
	bool active[n];
	fill(active, active+n, false);
	
	for(int x=0;x<maxN;x++){
		for(auto idx : w[x]){
			if(active[idx]){
				tree.update(h[idx][0], -1);
			} else {
				tree.update(h[idx][0], 1);
			}
			
			active[idx] ^= 1;
		}
		
		while(pos < m && z[pos].first == x){
			int idx = z[pos].second;
			int cnt = tree.query(v[idx][2]) - (v[idx][1] > 0 ? tree.query(v[idx][1]-1) : 0);
			
			ans += cnt;

			pos++;
		}
	}
	
	cout << ans << "\n";
    return 0;
}


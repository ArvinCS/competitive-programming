#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3e5 + 5;

struct SegTree {
	int tree[4*maxN];
	
	void reset(){
		fill(tree, tree+4*maxN, 0);
	}
	
	void update(int v, int curL, int curR, int pos, int val){
		if(curL > curR) return;
		
		int curM = (curL+curR) >> 1;
		if(curL == curR){
			tree[v] = val;
		} else {
			if(pos <= curM){
				update(2*v+1, curL, curM, pos, val);
			} else {
				update(2*v+2, curM+1, curR, pos, val);
			}
			
			tree[v] = tree[2*v+1] + tree[2*v+2];
		}
	}
	
	int query(int v, int curL, int curR){
		if(tree[v] == curR-curL+1) return -1;
		if(curL > curR) return -1;
		
		int curM = (curL+curR) >> 1;
		if(curL == curR){
			return curL;
		} else {
			int r = (curR-curM);
			if(tree[2*v+2] == r){
				return query(2*v+1, curL, curM);
			} else {
				return query(2*v+2, curM+1, curR);
			}
		}
	}
};

SegTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	tree.reset();
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		map<int, int> freq;
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			freq[a[x]]++;
		}
		
		set<pair<int, int>> st;
		for(int x=0;x<m;x++){
			int val1, val2;
			cin >> val1 >> val2;
			
			st.insert({val1, val2});
			st.insert({val2, val1});
		}
		
		vector<int> v[n+1];
		for(auto p : freq){
			v[p.second].push_back(p.first);
		}
		
		for(int x=0;x<n;x++){
			if(!v[x].empty()){
				reverse(v[x].begin(), v[x].end());
			}
		}

		ll ans = 0;
		for(int x=1;x<=n;x++){
			for(auto val : v[x]){
				for(int y=1;y<=x;y++){
					for(auto val2 : v[y]){
						if(val != val2 && !st.count({val, val2})){
							ans = max(ans, (val+val2)*1ll*(x+y));
							break;
						}
					}
				}
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}


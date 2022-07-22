#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e6 + 5;

struct Fenwick {
	ll tree[maxN];
	
	void reset(int n){
		fill(tree, tree+maxN, 0);
	}
	
	void update(int pos, ll val){
		pos++;
		
		while(pos < maxN){
			tree[pos] += val;
			
			pos += pos&(-pos);
		}
	}
	
	ll query(int pos){
		pos++;
		
		ll ans = 0;
		while(pos > 0){
			ans += tree[pos];
			
			pos -= pos&(-pos);
		}
		return ans;
	}
};

Fenwick tree;
ll lazy[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	tree.reset(n+2);
	
	set<tuple<int, int, int>> st;
	fill(lazy, lazy+maxN, 0);
	
	st.insert(make_tuple(n, 1, 1));
	for(int i=0;i<q;i++){
		string s;
		cin >> s;
		
		if(s == "Color"){
			int l, r, c;
			cin >> l >> r >> c;
			
			auto itLeft = *st.lower_bound(make_tuple(l, -1, -1));
			if(get<1>(itLeft) < l && get<0>(itLeft) >= l){
				st.erase(itLeft);
				st.insert(make_tuple(get<0>(itLeft), l, get<2>(itLeft)));
				st.insert(make_tuple(l-1, get<1>(itLeft), get<2>(itLeft)));
			}
			
			auto itRight = *st.lower_bound(make_tuple(r, -1, -1));
			if(get<1>(itRight) <= r && get<0>(itRight) > r){
				st.erase(itRight);
				st.insert(make_tuple(get<0>(itRight), r+1, get<2>(itRight)));
				st.insert(make_tuple(r, get<1>(itRight), get<2>(itRight)));
			}
			
			auto it = st.lower_bound(make_tuple(l, -1, -1));
			while(it != st.end() && get<1>(*it) <= r){			
				tree.update(get<0>(*it)+1, -lazy[get<2>(*it)]);
				tree.update(get<1>(*it), lazy[get<2>(*it)]);
				
				st.erase(it);
				it = st.lower_bound(make_tuple(l, -1, -1));
			}
			
			tree.update(r+1, lazy[c]);
			tree.update(l, -lazy[c]);
			st.insert(make_tuple(r, l, c));
		} else if(s == "Add"){
			int c;
			ll val;
			cin >> c >> val;
			
			lazy[c] += val;
//			tree.updateValue(0, 0, n-1, 0, n-1, c, val);
		} else {
			int pos;
			cin >> pos;
			
			cout << tree.query(pos) + lazy[get<2>(*st.lower_bound(make_tuple(pos, -1, -1)))] << "\n";
		}
	}
    return 0;
}


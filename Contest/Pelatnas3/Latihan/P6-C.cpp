#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ordered_set tree <pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>

const ll maxA = 1e16;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	ll s, c;
	cin >> n >> m >> s >> c;
		
	int a[n], b[m], nxt[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<m;x++){
		cin >> b[x];
	}
	
	for(int x=0;x<n;x++){
		auto it = lower_bound(a, a+n, a[x]-(c%s)+1);
		if(it == a){
			it = lower_bound(a, a+n, s-((c%s)-a[x])+1);
		}
		
		nxt[x] = (it - a) - 1;
	}
	
	vector<int> cyc;
	bool visited[n];
	fill(visited, visited+n, false);
	
	ll cost = 0;
	vector<int> v;
	int cur = 0;
	while(!visited[cur]){
		visited[cur] = true;
		v.push_back(cur);
		
		cost += c/s * s + (cur <= nxt[cur] ? s - a[nxt[cur]] + a[cur] : a[cur] - a[nxt[cur]]);
		cur = nxt[cur];
	}
	
	if(cur == 0){
		cyc = v;
	} else {
		while(true){
			assert(v.size() > 1);
			fill(visited, visited+n, false);
			
			int prv = v[1];
			cost = 0;
			cur = v[1];
			v.clear();
			while(!visited[cur]){
				visited[cur] = true;
				v.push_back(cur);
				
				cost += (c-1)/s * s + (cur <= nxt[cur] ? s - a[nxt[cur]] + a[cur] : a[cur] - a[nxt[cur]]);
//				cout << cur << " -> " << nxt[cur] << " = " << (c-1)/s * s + (cur <= nxt[cur] ? s - a[nxt[cur]] + a[cur] : a[cur] - a[nxt[cur]]) << "\n";
				cur = nxt[cur];
			}
			
			if(cur == prv){
				cyc = v;
				break;
			}
		}
	}
	assert(cost > 0);
	
	vector<pair<ll, int>> pending[n];
	int q;
	cin >> q;
	
	ll ans[q];
	fill(ans, ans+q, 0);
	
	for(int x=0;x<q;x++){
		int pos;
		ll t;
		cin >> pos >> t;
		
		pos--;
//		assert(t > 0);
		pending[pos].push_back({t, x});
	}
	
	vector<pair<int, ll>> box[n];
	int pos = -1;
	for(int x=0;x<m;x++){
		while(pos+1 < n && a[pos+1] < b[x]){
			pos++;
		}
		
		box[(pos+n)%n].push_back({x, (a[(pos+n)%n] <= b[x] ? b[x] - a[(pos+n)%n] : s - a[(pos+n)%n] + b[x])});
	}
	
	bool done[n];
	fill(done, done+n, false);
	
	vector<int> topo;
	for(int x=0;x<n;x++){
		if(!done[x]){
			vector<int> v;
			int cur = x;
			while(!done[cur]){
				v.push_back(cur);
				done[cur] = true;
				cur = nxt[cur];
			}
			while(!v.empty()){
				topo.push_back(v.back());
				v.pop_back();
			}
		}	
	}
	reverse(topo.begin(), topo.end());
	
	ordered_set st;
	for(int y=0;y<topo.size();y++){
		int x = topo[y];
		if(!visited[x] && x == nxt[x]){
//			cout << x << " ==\n";
			for(auto p : box[x]){
				st.insert({p.second, p.first});
			}
			
			ll dist = ((c-1)/s * s + s);
			for(auto p : pending[x]){
				ans[p.second] += (p.first/dist + 1) * 1ll * st.order_of_key({p.first+1, -1}) - (st.order_of_key({p.first+1, -1}) - st.order_of_key({p.first%dist+1, -1}));	
			}
			
			for(auto p : box[x]){
				box[nxt[x]].push_back({p.first, (c-1)/s * s + (x <= nxt[x] ? s - a[nxt[x]] + a[x] : a[x] - a[nxt[x]]) + p.second});
			}
			st.clear();
		} else if(!visited[x]){
//			cout << x << " " << box[x].size() << " -> " << nxt[x] << " ====\n";
			for(auto p : box[x]){
				st.insert({p.second, p.first});
			}
			
			for(auto p : pending[x]){
				ans[p.second] += st.order_of_key({p.first+1, -1});
			}
			
			for(auto p : box[x]){
				box[nxt[x]].push_back({p.first, (c-1)/s * s + (x <= nxt[x] ? s - a[nxt[x]] + a[x] : a[x] - a[nxt[x]]) + p.second});
			}
			st.clear();
		}
	}
	
	ll lazy = 0;
	vector<pair<ll, ll>> del[n];
	for(int x=0;x<2*cyc.size();x++){
		int idx = cyc[x%cyc.size()];
		if(del[idx].empty()){
			for(auto p : box[idx]){
				st.insert({p.second-lazy, p.first});
				del[idx].push_back({p.second-lazy, p.first});
				assert(p.second < cost);
//				if(p.second >= cost){
//					cout << p.second << " " << cost << " " << p.first << "-\n";
//				}
//				cout << "+ " << p.second-lazy << " " << p.second << "-" << lazy << " " << p.first << "\n"; 
			}
		} else {
			for(auto val : del[idx]){
				auto it = st.find(val);
				assert(it != st.end());
				st.erase(it);
//				cout << "- " << val.first << "\n";
			}
		}
		
		for(auto p : pending[idx]){
//			cout << idx << " " << st.size() << " = " << p.first << " " << p.second << " " << lazy << " " << cost << " -> " << (st.order_of_key({p.first+1-lazy, -1})) << " - " << (st.order_of_key({p.first+1-lazy, -1}) - st.order_of_key({p.first%cost-lazy+1, -1})) << "\n";
			ans[p.second] += (p.first/cost + 1) * 1ll * st.order_of_key({p.first+1-lazy, -1}) - (st.order_of_key({p.first+1-lazy, -1}) - st.order_of_key({p.first%cost-lazy+1, -1}));
//			cout << "+= " << (p.first/cost + 1) * 1ll * st.order_of_key({p.first+1-lazy, -1}) - (st.order_of_key({p.first+1-lazy, -1}) - st.order_of_key({p.first%cost-lazy+1, -1})) << " " << p.first-lazy+1 << "," << p.first%cost-lazy+1 << "\n";
			assert((p.first/cost + 1) * 1ll * st.order_of_key({p.first+1-lazy, -1}) - (st.order_of_key({p.first+1-lazy, -1}) - st.order_of_key({p.first%cost-lazy+1, -1})) >= 0);
			assert(p.first/cost >= 0);
		}
		
//		assert(idx != nxt[idx]);
		lazy += (c-1)/s * s + (idx <= nxt[idx] ? s - a[nxt[idx]] + a[idx] : a[idx] - a[nxt[idx]]);//(idx < nxt[idx] ? a[nxt[idx]] - a[idx] : s - a[idx] + a[nxt[idx]]);
		assert(lazy >= 0);
	}
	
	for(int x=0;x<q;x++){
		assert(ans[x] >= 0);
		cout << ans[x] << "\n";
	}
    return 0;
}


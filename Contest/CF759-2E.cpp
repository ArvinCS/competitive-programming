#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

const int maxN = 1e6 + 5;

vector<int> adj[maxN];

void dfs(int curNode, vector<int> &v){
	v.push_back(curNode);
	for(auto nxt : adj[curNode]){
		dfs(nxt, v);
		v.push_back(curNode);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, q;
		cin >> n >> q;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			a[x]--;
			adj[x].clear();
		}
		
		int p[n];
		p[0] = -1;
		for(int x=1;x<n;x++){
			cin >> p[x];
			
			p[x]--;
			adj[p[x]].push_back(x);
		}
		
		vector<array<int, 3>> w[n];
		for(int x=0;x<q;x++){
			int v, l, k;
			cin >> v >> l >> k;
			
			w[v-1].push_back({l, k, x});
		}
		
		ordered_set st;
		vector<int> v;
		dfs(0, v);
		
		int ans[q], cnt[n];
		fill(cnt, cnt+n, 0);
		fill(ans, ans+q, -2);
		
		cnt[a[0]]++;
		st.insert({cnt[a[0]], a[0]});
		
		while(!w[0].empty()){
			int l = w[0].back()[0], k = w[0].back()[1], idx = w[0].back()[2];
			w[0].pop_back();
			
			int lowest = st.order_of_key({l-1, 1e9});
			
			auto it = st.find_by_order(lowest+k-1);
			
			if(it == st.end()){
				ans[idx] = -1;
				continue;
			}
			
			ans[idx] = (*it).second+1;
		}
		
		int prvNode = 0;
		for(int x=1;x<v.size();x++){
			int curNode = v[x];
			
			if(p[curNode] == prvNode){ // go down
				auto it = st.find({cnt[a[curNode]], a[curNode]});
				if(it != st.end()) st.erase(it);
				
				cnt[a[curNode]]++;
				
				st.insert({cnt[a[curNode]], a[curNode]});
			} else if(p[prvNode] == curNode){ // go up
				auto it = st.find({cnt[a[prvNode]], a[prvNode]});
				if(it != st.end()) st.erase(it);
				
				cnt[a[prvNode]]--;
				
				st.insert({cnt[a[prvNode]], a[prvNode]});
			}
			
			while(!w[curNode].empty()){
				int l = w[curNode].back()[0], k = w[curNode].back()[1], idx = w[curNode].back()[2];
				w[curNode].pop_back();
				
				int lowest = st.order_of_key({l-1, 1e9});
				
				auto it = st.find_by_order(lowest+k-1);
				
				if(it == st.end()){
					ans[idx] = -1;
					continue;
				}
				
				ans[idx] = (*it).second+1;
			}
			
			prvNode = curNode;
		}
			
		for(int x=0;x<q;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
			assert(ans[x] >= -1);
		}
		cout << "\n";
	}
	
    return 0;
}


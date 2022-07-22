#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<int> adj[maxN];
int sz[maxN], n;
multiset<int> st;

void dfs(int curNode, int prvNode){
	sz[curNode] = 1;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode);
			sz[curNode] += sz[nxt];
		}
	}	
}

int dfs2(int curNode, int prvNode){
	int ans = 1e9;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			auto itTop = st.lower_bound((n-sz[nxt]+1)/2);
			if(itTop != st.end()){
				int rem = n-(sz[nxt]+*itTop);
				
				ans = min(ans, max(rem, max(*itTop, sz[nxt])) - min(rem, min(*itTop, sz[nxt])));
			}
			if(itTop != st.begin()){
				itTop--;
				int rem = n-(sz[nxt]+*itTop);
				
				ans = min(ans, max(rem, max(*itTop, sz[nxt])) - min(rem, min(*itTop, sz[nxt])));
			}
			
			st.insert(n-sz[nxt]);
			
			ans = min(ans, dfs2(nxt, curNode));
			
			st.erase(st.find(n-sz[nxt]));
			st.insert(sz[nxt]);
		}
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
		
	cin >> n;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs(0, 0);
	
	cout << dfs2(0, 0) << "\n";
	return 0;
}

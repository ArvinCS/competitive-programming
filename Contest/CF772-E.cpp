#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<pair<int, int>> adj[maxN];
int par[maxN], pos[maxN], ori[maxN];
set<int> st;

bool dfs(int curNode, int parity, int val){
	par[curNode] = parity;
	bool valid = true;
	for(auto nxt : adj[curNode]){
		if(nxt.second == 1){
			if(par[nxt.first] == -1){
				pos[nxt.first] = pos[curNode]+(val == 1 ? *(st.rbegin()) : *st.lower_bound(0));
				valid &= dfs(nxt.first, parity^nxt.second, val*-1);
			}
			
			valid &= (par[nxt.first] == parity^nxt.second);
		}
	}
	return valid;
}

bool dfs2(int curNode, int right){
	ori[curNode] = right;
	
	bool valid = true;
	for(auto nxt : adj[curNode]){
		if(ori[nxt.first] == -1){
			valid &= dfs2(nxt.first, right^1);
		}
		valid &= (ori[nxt.first] != ori[curNode]);
	}
	return valid;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		int t, a, b;
		cin >> t >> a >> b;
		
		a--; b--; t--;
		adj[a].push_back({b, t});
		adj[b].push_back({a, t});
	}
	
	fill(ori, ori+n, -1);
	for(int x=0;x<n;x++){
		if(ori[x] == -1){
			if(!dfs2(x, 1)){
				cout << "No\n";
				return 0;
			}
		}
	}
	
	fill(par, par+n, -1);
	
	int left = -1, right = 1;
	for(int x=0;x<n;x++){
		if(par[x] == -1){
			if(ori[x]){
				pos[x] = right;
				right += 2000002;
			} else {
				pos[x] = left;
				left -= 2000002;
			}
			
			if(!dfs(x, 0, 1000000 * (ori[x] ? 1 : -1))){
				cout << "No\n";
				return 0;
			}
		}
	}
	
	cout << "Yes\n";
	for(int x=0;x<n;x++){
		cout << (ori[x] ? 'R' : 'L') << " " << pos[x] << "\n";
	}
    return 0;
}


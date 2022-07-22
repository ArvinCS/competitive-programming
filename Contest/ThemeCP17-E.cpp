#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3e5 + 5;

vector<int> adj[maxN];
bool visited[maxN];
int table[maxN];

void dfs(int curNode){
	visited[curNode] = true;
	table[curNode] = 1;
	for(auto nxt : adj[curNode]){
		if(!visited[nxt]){
			dfs(nxt);
		}
		table[curNode] = max(table[curNode], table[nxt]+1);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<array<int, 3>> v;
	for(int x=0;x<m;x++){
		int idx, l, r;
		cin >> idx >> l >> r;
		
		idx--;
		v.push_back({l, 1, idx});
		v.push_back({r+1, 0, idx});
	}
	
	sort(v.begin(), v.end());
	
	int cnt[n];
	fill(cnt, cnt+n, 0);
	
	set<int> st;
	for(int x=0;x<v.size();x++){
		if(v[x][1] == 0){
			cnt[v[x][2]]--;
			if(cnt[v[x][2]] == 0) st.erase(v[x][2]);
		} else if(v[x][1] == 1){
			if(cnt[v[x][2]] == 0){
				auto it = st.lower_bound(v[x][2]);
				if(it != st.end()){
					adj[v[x][2]].push_back(*it);	
				}
				if(it != st.begin()){
					it--;
					adj[*it].push_back(v[x][2]);
				}
				st.insert(v[x][2]);
			}
			cnt[v[x][2]]++;
		}
	}
	
	fill(table, table+n, -1);

	pair<int, int> mx = {-1, -1};
    for(int x=0;x<n;x++){
    	if(table[x] == -1){
    		dfs(x);
		}
		mx = max(mx, {table[x], x});
	}
	
	bool valid[n];
	fill(valid, valid+n, false);
	
	bool stop = false;
	int cur = mx.second;
	while(!stop){
		stop = true;
		valid[cur] = true;
		for(auto nxt : adj[cur]){
			if(table[nxt] == table[cur]-1){
				cur = nxt;
				stop = false;
				break;
			}
		}
	}
	
	cout << n-mx.first << "\n";
	bool one = true;
	for(int x=0;x<n;x++){
		if(!valid[x]){
			if(!one) cout << " ";
			cout << x+1;
			one = false;
		}
	}
	cout << "\n";
	return 0;
}


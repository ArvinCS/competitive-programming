#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const int maxN = 1e5 + 5;
const int logN = log2(maxN);

vector<int> adj[maxN];
int dp[maxN], level[maxN], mx[maxN];
pair<int, int> edge[maxN], parrent[maxN][logN+1];

void dfs(int curNode, int prvNode){	
	int up = 0, down = 0, cnt = 0;
	for(auto nxt : adj[curNode]){
		if(nxt == prvNode) continue;
		
		if(level[nxt] == -1){
			level[nxt] = level[curNode]+1;
			dfs(nxt, curNode);
			cnt += dp[nxt];
		} else {
			if(level[nxt] > level[curNode]){
				down++;
			} else {
				up++;
			}
		}
	}
	
	dp[curNode] = up - down + cnt;
}

void dfs2(int curNode, int prvNode, int val){
	if(dp[curNode] == 0) val = 0;
	val = max(val, dp[curNode]);
	
	for(int x=1;x<=logN;x++){
		parrent[curNode][x].first = parrent[parrent[curNode][x-1].first][x-1].first;
		parrent[curNode][x].second = max(parrent[curNode][x-1].second, parrent[parrent[curNode][x-1].first][x-1].second);
		cout << curNode << "," << x << " -> " << parrent[curNode][x].first << " " << parrent[curNode][x].second << "\n";
	}
	
	bool zero = true;
	for(auto nxt : adj[curNode]){
		if(nxt == prvNode) continue;
		
		if(level[nxt] == -1){
			level[nxt] = level[curNode]+1;
			parrent[nxt][0] = {curNode, dp[curNode]};
			dfs2(nxt, curNode, val);
			
			if(mx[nxt] > 0) zero = false;
			mx[curNode] = max(mx[curNode], mx[nxt]);
		}
	}
	
	if(zero){
		mx[curNode] = 0;
	}
	
	mx[curNode] = max(mx[curNode], val);
	mx[curNode] = max(mx[curNode], dp[curNode]);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		cin >> edge[x].first >> edge[x].second;
		
		edge[x].first--; edge[x].second--;
		adj[edge[x].first].push_back(edge[x].second);
		adj[edge[x].second].push_back(edge[x].first);
	}
	
	fill(level, level+n, -1);
	
	level[0] = 0;
	dfs(0, 0);
	
	fill(level, level+n, -1);
	
	level[0] = 0;
	parrent[0][0] = {0, 0};
	dfs2(0, 0, 0);
	
	for(int x=0;x<n;x++){
		cout << x << " = " << dp[x] << "," << mx[x] << "\n";
	}
	
	vector<int> ans;
	for(int x=0;x<m;x++){
		int a = edge[x].first, b = edge[x].second;
		
		if(level[a] > level[b]){
			swap(a, b);
		}
		
		cout << x << " " << level[a] << "," << level[b] << " :\n";
		int val = dp[b], val2 = mx[b];
		for(int i=logN;i>=0;i--){
			if(level[a] < level[b]-(1 << i)){
				cout << b << " " << parrent[b][i].first << " ? " << parrent[b][i].second << "\n";
				val = max(val, parrent[b][i].second);
				b = parrent[b][i].first;
			}
		}
		cout << val << " = " << mx[b] << "\n";
		
		if(mx[b] == 1){
			ans.push_back(x+1);
		}
	}
	
	cout << ans.size() << "\n";
	for(int x=0;x<ans.size();x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

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

int color[maxN], mx[maxN];
ll ans[maxN];
map<int, int> mp[maxN];
vector<int> adj[maxN];

void merge(int x, int y){
	if(mp[x].size() < mp[y].size()){
		swap(mp[x], mp[y]);
		ans[x] = ans[y];
		mx[x] = mx[y];
	}
	
	for(auto &m : mp[y]){
		mp[x][m.first] += m.second;
		
		int val = mp[x][m.first];
		if(val > mx[x]){
			mx[x] = val;
			ans[x] = m.first;
		} else if(val == mx[x]){
			ans[x] += m.first;
		}
	}
}

void dfs(int curNode, int prvNode){
	mx[curNode] = 1;
	ans[curNode] = color[curNode];
	mp[curNode][color[curNode]]++;
	
	for(auto &nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode);
			merge(curNode, nxt);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> color[x];
	}
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs(0, -1);
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

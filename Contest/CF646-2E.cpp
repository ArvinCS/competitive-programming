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

const int maxN = 2e5 + 5;

vector<int> adj[maxN];
int sz[maxN], one[maxN], depth[maxN], b[maxN], c[maxN];
ll a[maxN], need[maxN][2];
bool change[maxN], visited[maxN];

int cnt1 = 0, cnt2 = 0;

bool customSort(int x, int y){
	if(a[x] == a[y]) return depth[x] < depth[y];
	return a[x] < a[y];
}

void dfs(int curNode, int prvNode, int level){
	depth[curNode] = level;
	need[curNode][0] = need[curNode][1] = 0;
	if(change[curNode]){
		need[curNode][b[curNode]]++;
	}
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode, level+1);
			sz[curNode] += sz[nxt];
			need[curNode][0] += need[nxt][0];
			need[curNode][1] += need[nxt][1];
		}
	}
}

void dfs2(int curNode){
	need[curNode][0] = need[curNode][1] = 0;
	if(change[curNode]){
		need[curNode][b[curNode]]++;
	}
	
	for(auto nxt : adj[curNode]){
		if(depth[nxt] > depth[curNode]){
			if(!visited[nxt]) dfs2(nxt);
			need[curNode][0] += need[nxt][0];
			need[curNode][1] += need[nxt][1];
		}
	}
}

void dfs3(int curNode){
	visited[curNode] = true;
	for(auto nxt : adj[curNode]){
		if(depth[nxt] > depth[curNode] && !visited[nxt]){
			dfs3(nxt);
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
	
	ll sum1 = 0, sum2 = 0;
	vector<int> v;
	
	for(int x=0;x<n;x++){
		cin >> a[x] >> b[x] >> c[x];
	}

	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int x=0;x<n;x++){
		sz[x] = 1;
		one[x] = b[x];
		v.push_back(x);
		change[x] = (b[x] != c[x]);
		
		sum1 += b[x];
		sum2 += c[x];
	}
	
	fill(visited, visited+n, false);
	dfs(0, -1, 0);
	sort(v.begin(), v.end(), customSort);
	
	if(sum1 != sum2){
		cout << "-1\n";
		return 0;
	}
	
	ll ans = 0;
	for(auto &curNode : v){
		if(visited[curNode]) continue;
		dfs2(curNode);
			
		ll mn = min(need[curNode][0], need[curNode][1]);
		ans += mn * 2 * a[curNode];
		need[curNode][0] -= mn;
		need[curNode][1] -= mn;
		
		dfs3(curNode);
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar


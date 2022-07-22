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

const int maxN = 5e3 + 5;

vector<pair<int, int>> adj[maxN];
pair<int, int> prv[maxN];
int source, target, val[maxN];

void dfs(int curNode, int prvNode, int mn){
	if(curNode == target){
		int node = curNode;
		while(node != source){
			val[prv[node].second] = mn;
			node = prv[node].first;
		}
		
		return;
	}
	
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			prv[nxt.first] = {curNode, nxt.second};
			dfs(nxt.first, curNode, mn);
		}
	}
}

int dfs2(int curNode, int prvNode, int mn){
	if(curNode == target){
		return mn;
	}
	
	int ans = 1e6;
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			prv[nxt.first] = {nxt.first, nxt.second};
			ans = min(ans, dfs2(nxt.first, curNode, min(val[nxt.second], mn)));
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back({b, x});
		adj[b].push_back({a, x});
	}
	
	cin >> m;
	
	int a[m], b[m], c[m];
	vector<pair<int, int>> v;
	for(int x=0;x<m;x++){
		cin >> a[x] >> b[x] >> c[x];
		a[x]--; b[x]--;
		
		v.push_back({c[x], x});
	}

	sort(v.begin(), v.end());
	
	fill(val, val+maxN, 1e6);
	
	for(int x=0;x<m;x++){
		source = a[v[x].second];
		target = b[v[x].second];
		
		dfs(source, source, c[v[x].second]);
	}
	
	bool valid = true;
	for(int x=0;x<m;x++){
		source = a[v[x].second];
		target = b[v[x].second];
		
		int mn = dfs2(source, source, 1e6);
		if(mn != c[v[x].second]){
			valid = false;
		}
	}
	
	if(valid){
		for(int x=0;x<n-1;x++){
			if(x > 0) cout << " ";
			cout << val[x];
		}
		cout << "\n";
	} else {
		cout << "-1\n";
	}
    return 0;
}


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

const int maxN = 8e5 + 5;

vector<pair<int, int>> adj[2*maxN];
tuple<int, int, int> edge[maxN];
int parrent[2*maxN], sz[maxN];
vector<int> v[maxN];

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

void merge(int x, int y){
	int a = getParrent(x), b = getParrent(y);
	
	if(a != b){
		if(sz[a] < sz[b]) swap(a, b);
		
		parrent[b] = a;
		sz[a] += sz[b];
		for(auto node : v[b]){
			v[a].push_back(node);
		}
	}
}

ll dfs(int curNode, int prvNode, int target, int mn){
	ll ans = 0;
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			if(getParrent(nxt.first) == target){
				ans += min(mn, nxt.second);
			}
			ans += dfs(nxt.first, curNode, target, min(mn, nxt.second));
			ans %= mod;
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

	us t;
	cin >> t;
	
	for(us i=1;i<=t;i++){
		int n;
		cin >> n;
		
		for(int x=0;x<n;x++){
			adj[x].clear();
			v[x].clear();
			v[x].push_back(x);
			parrent[x] = x;
			sz[x] = 1;
		}
		
		for(int x=0;x<n-1;x++){
			int a, b, c;
			cin >> a >> b >> c;
			
			a--; b--;
			adj[a].push_back({b, c});
			adj[b].push_back({a, c});
			edge[x] = make_tuple(c, a, b);
		}
		
		sort(edge, edge+n-1);
		
		ll prefix[n], suffix[n];
		ll ans = 1, sum = 0;
		for(int x=0;x<n-1;x++){
			int a = get<1>(edge[x]), b = get<2>(edge[x]), c = get<0>(edge[x]);
			a = getParrent(a); b = getParrent(b);
			
			if(sz[a] < sz[b]){
				swap(a, b);	
			}
			for(auto node : v[b]){
				sum += dfs(node, node, a, 20);
			}
			
			merge(a, b);
			prefix[x] = sum;
		}
		
		sum = 0;
		for(int x=0;x<n;x++){
			v[x].clear();
			v[x].push_back(x);
			parrent[x] = x;
			sz[x] = 1;
		}
		for(int x=n-2;x>=0;x--){
			int a = get<1>(edge[x]), b = get<2>(edge[x]), c = get<0>(edge[x]);
			a = getParrent(a); b = getParrent(b);
			
			if(sz[a] < sz[b]){
				swap(a, b);	
			}
			for(auto node : v[b]){
				sum += dfs(node, node, a, 20);
			}
			
			merge(a, b);
			suffix[x] = sum;
		}
		
		for(int x=0;x<n-1;x++){
			int a = get<1>(edge[x]), b = get<2>(edge[x]), c = get<0>(edge[x]);
			a = getParrent(a); b = getParrent(b);
			
			if(v[a].size() < v[b].size()){
				swap(a, b);	
			}
			
			ll val = 0;
			if(x > 0) val += prefix[x-1];
			if(x+1 < n-1) val += suffix[x+1];
			
			cout << val << "\n";
			for(auto node : v[b]){
				val += dfs(node, node, a, 20);
			}
			cout << val << " ---\n";
			ans = (ans * val) % mod;
//			cout << prefix[x] << " ";
		}
		cout << "\n";
		
		cout << ans << " " << sum << "\n";
	}

    return 0;
}


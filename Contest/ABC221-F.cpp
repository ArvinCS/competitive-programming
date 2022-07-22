#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define smod 998244353

const int maxN = 2e5 + 5;

int level[maxN], sublevel[maxN];
vector<int> adj[maxN];

int dfs(int curNode, int prvNode, int depth){
	level[curNode] = depth;
	sublevel[curNode] = depth;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			sublevel[curNode] = max(sublevel[curNode], dfs(nxt, curNode, depth+1));
		}
	}
	
	return sublevel[curNode];
}

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % smod;
		
		y >>= 1;
		x = (x*x) % smod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	if(n == 2){
		cout << 1 << "\n";
		return 0;
	}

	int root = 0;
	for(int x=0;x<n;x++){
		if(adj[x].size() == 1){
			root = x;
			break;
		}
	}
	
	dfs(root, root, 0);
	
	for(int x=0;x<n;x++){
		if(level[x] == sublevel[root]){
			root = x;
			break;
		}
	}
	
	dfs(root, root, 0);
	
	cout << root << " " << sublevel[root] << "\n";
	
	ll ans = 0;
	if(sublevel[root] % 2 == 0){
		for(int x=0;x<n;x++){
			if(level[x] == sublevel[root]/2){
				queue<tuple<int, int, int>> q;
				q.push(make_tuple(x, x, 0));
				
				ll cnt = 0, cnt2 = 0;
				while(!q.empty()){
					tuple<int, int, int> t = q.front();
					q.pop();
					
					int curNode = get<0>(t), prvNode = get<1>(t), dist = get<2>(t);
					
					if(dist == sublevel[root]/2){
						cnt++;
					}
					
					if(dist >= sublevel[root]/2) continue;
					for(auto nxt : adj[curNode]){
						if(nxt != prvNode){
							q.push(make_tuple(nxt, curNode, dist+1));
						}
					}
				}
				
				if(cnt >= 2){
					ans += (powmod(2, cnt) - cnt - 1 + smod) % smod;
					ans %= smod;
				}
				break;
			}
		}
	} else {
		for(int x=0;x<n;x++){
			if(level[x] == sublevel[root]/2){
				queue<tuple<int, int, int>> q;
				q.push(make_tuple(x, x, 0));
				
				ll cnt = 0, cnt2 = 0;
				while(!q.empty()){
					tuple<int, int, int> t = q.front();
					q.pop();
					
					int curNode = get<0>(t), prvNode = get<1>(t), dist = get<2>(t);
					
					if(dist == sublevel[root]/2){
						cnt++;
					}
					if(dist == (sublevel[root]+1)/2){
						cnt2++;
					}
					
					if(dist >= (sublevel[root]+1)/2) continue;
					for(auto nxt : adj[curNode]){
						if(nxt != prvNode){
							q.push(make_tuple(nxt, curNode, dist+1));
						}
					}
				}
				
				cout << x << " = " << cnt << " " << cnt2 << " " << sublevel[root] << "\n";
				if(cnt2 >= 1){
					ans += (cnt2 * (cnt-1)) % smod;
					ans %= smod;
				}
				break;
			}
		}
	}
	cout << ans << "\n";
    return 0;
}


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
const int lgN = log2(maxN)+1;

int n;
vector<int> adj[maxN];
int parrent[lgN+2][maxN];
int lvl[maxN], inTime[maxN], outTime[maxN], t = 0;
ll sz[maxN];

int dfs(int curNode){
	inTime[curNode] = t++;
	for(int x=1;x<=lgN;x++){
		parrent[x][curNode] = parrent[x-1][parrent[x-1][curNode]];
	}
	
	int cnt = 1;
	for(auto nxt : adj[curNode]){
		if(nxt != parrent[0][curNode]){
			lvl[nxt] = lvl[curNode]+1;
			parrent[0][nxt] = curNode;
			cnt += dfs(nxt);
		}
	}
	sz[curNode] = cnt;
	outTime[curNode] = t++;
	
	return sz[curNode];
}

bool inside(int a, int b){
	return (inTime[a] <= inTime[b] && outTime[b] <= outTime[a]);
}

bool insideOther(int a, int b){
	return inside(a,b) || inside(b,a);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us tc;
	cin >> tc;
	
	while(tc--){
		cin >> n;
		
		t = 0;
		for(int x=0;x<=n;x++) adj[x].clear();
		parrent[0][0] = 0;
		
		for(int x=0;x<n-1;x++){
			int a, b;
			cin >> a >> b;
			
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		lvl[0] = 0;
		dfs(0);
		lvl[n] = inTime[n] = outTime[n] = inf_int;
		sz[n] = 0;
		
		bool possible = true;
		set<pair<int, int>> path1, path2;
		for(int k=0;k<=n;k++){
			ll ans = 0;
			
			if(k == 0){
				for(auto nxt : adj[k]){
					ans += sz[nxt]*1ll*(sz[nxt]-1)/2;
				}
			} else if(k == 1){
				ll sz1 = 0;
				for(auto nxt : adj[0]){
					ll tmp = sz[nxt];
					if(inside(nxt, k)){
						tmp -= sz[k];
					}
					
					ans += sz1*tmp + tmp;
					sz1 += tmp;
				}
			} else {
				if(possible){
					int node1 = (path1.size() == 0 ? -1 : (*path1.rbegin()).second);
					int node2 = (path2.size() == 0 ? -1 : (*path2.rbegin()).second);

					ll sz1 = (node1 != -1 ? sz[node1] : 0), sz2 = (node2 != -1 ? sz[node2] : 0);
					if(node1 >= 0){
						if(inside(node1, k)){
							sz1 -= sz[k];
						} else if(inside(k, node1)){
							sz1 -= sz[node1];
						}
					}
					
					if(node2 >= 0){
						if(inside(node2, k)){
							sz2 -= sz[k];
						} else if(inside(k, node2)){
							sz2 -= sz[node2];
						}
					} else {
						int cur = node1;
						for(int x=lgN;x>=0;x--){
							if(lvl[parrent[x][cur]] >= 1){
								cur = parrent[x][cur];
							}
						}
						
						sz2 = sz[0] - sz[cur] - (insideOther(cur, k) ? 0 : sz[k]);
					}
					
//					cout << k << " -> " << node1 << " " << sz[node1] << " " << sz1 << " " << node2 << " " << sz2 << "\n";
					ans += sz1*sz2;
				}
			}
			
			if(k > 0) cout << " ";
			cout << (possible ? ans : 0);
			
			if(k > 0 && k < n && possible){
//				cout << (path1.size() == 0 ? -1 : (*path1.begin()).second) << "\n";
				if(path1.size() == 0 || insideOther((*path1.rbegin()).second, k)){
					path1.insert({lvl[k], k});
				} else {
					int cur = (*path1.begin()).second;
					for(int x=lgN;x>=0;x--){
						if(lvl[parrent[x][cur]] >= 1){
							cur = parrent[x][cur];
						}
					}
					if(insideOther(k, cur)){
						possible = false;
					}
					
					if(path2.size() == 0 || insideOther((*path2.rbegin()).second, k)){
						path2.insert({lvl[k], k});
					} else {
						possible = false;
					}
				}
			}
		}
		cout << "\n";
	}

    return 0;
}


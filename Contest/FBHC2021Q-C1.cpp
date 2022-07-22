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

const int maxN = 55;

vector<int> adj[maxN];
ll cnt[maxN], c[maxN], color[maxN];

void dfs(int curNode, int prvNode, int col, ll sum){
	sum += c[curNode];
	
	cnt[curNode] = sum;
	color[curNode] = col;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode, col, sum);
		}
	} 
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("gold_mine_chapter_1_input.txt","r",stdin);
//	freopen("gold_mine_chapter_1_output.txt","w",stdout);

	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int n, k;
		cin >> n >> k;
		
		for(int x=0;x<n;x++){
			cin >> c[x];
		}
		
		for(int x=0;x<n;x++){
			adj[x].clear();
			cnt[x] = 0;
		}
		
		for(int x=0;x<n-1;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		cnt[0] = c[0];
		for(int x=0;x<adj[0].size();x++){
			dfs(adj[0][x], 0, x, cnt[0]);
		}
		
		ll ans = 0, ans2 = 0, idx = -1;
		for(int x=0;x<n;x++){
			if(ans < cnt[x]){
				ans = cnt[x];
				idx = x;
			}
		}
		for(int x=1;x<n;x++){
			if(color[x] != color[idx]){
				ans2 = max(ans2, cnt[x]-cnt[0]);
			}
		}
		
		cout << "Case #" << i << ": " << ans+ans2 << "\n";
	}

    return 0;
}


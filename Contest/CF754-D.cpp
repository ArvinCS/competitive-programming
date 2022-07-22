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

int ans[maxN];
vector<int> adj[maxN];
int color[maxN];

int msb(int val){
	for(int i=30;i>=0;i--){
		if(val&(1 << i)) return i;
	}
	return -1;
}

void dfs(int curNode, int prvNode, int c){
	color[curNode] = c;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode, c^1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		for(int x=0;x<n;x++){
			adj[x].clear();
		}
		for(int x=0;x<n-1;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		dfs(0, 0, 0);
		
		int zero = 0;
		vector<int> v;
		for(int x=0;x<n;x++){
			if(color[x] == 0){
				zero++;
				v.push_back(x);
			}
		}
		
		bool used[31];
		fill(used, used+31, false);
		
		for(int i=20;i>=0;i--){
			int bit = (1 << i);
			int mn = max(0, min(bit, n-bit+1));
			
			if(zero >= mn){
				used[i] = true;
				zero -= mn;
				
				int cur = bit;
				while(mn > 0){
					ans[v.back()] = cur++;
					v.pop_back();
					mn--;
				}
			}
		}
		
		int cur = 1;
		for(int x=0;x<n;x++){
			if(color[x] == 1){
				while(used[msb(cur)]) cur++;
				ans[x] = cur++;
			}
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}


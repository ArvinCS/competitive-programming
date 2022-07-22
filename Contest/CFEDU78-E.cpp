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

const int maxN = 5e5 + 5;

vector<int> adj[maxN];
int cnt = 1;
pair<int, int> ans[maxN];

void dfs(int curNode, int prvNode, int s){
	ans[curNode].first = s;
	ans[curNode].second = cnt+adj[curNode].size()-(curNode != prvNode);
	
	int val = adj[curNode].size()-(curNode != prvNode);
	cnt += val+1;
	
	int tmp = 1;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode, ans[curNode].second-tmp);
			tmp++;
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
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0, 0, 0);
	
	for(int x=0;x<n;x++){
		cout << ans[x].first+1 << " " << ans[x].second+1 << "\n";
	}
    return 0;
}

